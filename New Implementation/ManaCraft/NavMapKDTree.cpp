// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "NavMapKDTree.h"

//
//
// NavMapKDTree()
//
//
//NavMapKDTree::NavMapKDTree() {
//
//}

//
//
// NavMapKDTree::Insert()
//
//
void NavMapKDTree::Insert(Waypoint* wp) {
	Insert(m_root, new Node(wp), 0);
}

//
//
// NavMapKDTree::Insert()
//
//
void NavMapKDTree::Insert(Node*& rootNode, Node* newNode, unsigned int depth) {
	// This or NearestWaypoint() isn't working properly
	// It's because of depth.. working on it
	if (rootNode == NULL) {
		rootNode = newNode;
	}
	else {
		if (depth % 2 == 0) {
			printf("X %i \n", depth);
			if (newNode->m_waypoint->Position().x < rootNode->m_waypoint->Position().x) {
				Insert(rootNode->left, newNode, depth + 1);
			}
			else {
				Insert(rootNode->right, newNode, depth + 1);
			}
		}
		else {
			printf("Y %i \n", depth);
			if (newNode->m_waypoint->Position().y < rootNode->m_waypoint->Position().y) {
				Insert(rootNode->left, newNode, depth + 1);
			}
			else {
				Insert(rootNode->right, newNode, depth + 1);
			}
		}
	}
}

//
//
// NavMapKDTree::TestTraverse()
//
//
void NavMapKDTree::TestTraverse() {
	TestTraverseInOrder(m_root);
}

//
//
// NavMapKDTree::TestTraverseInOrder()
//
//
void NavMapKDTree::TestTraverseInOrder(Node* rootNode) {
	if (rootNode == NULL) {
		return;
	}

	TestTraverseInOrder(rootNode->left);

	Vec3f tmp = rootNode->m_waypoint->Position();
	std::cout << tmp.ToString() << std::endl;

	TestTraverseInOrder(rootNode->right);
}

//
//
// NavMapKDTree::NearestWaypoint()
//
//
Waypoint* NavMapKDTree::NearestWaypoint(Vec3f pos) {
	m_nearestWP = m_root->m_waypoint;

	NearestWaypoint(m_root, pos, 0);

	Vec3f tmp = m_nearestWP->Position();

	return m_nearestWP;
}

//
//
// NavMapKDTree::NearestWaypoint()
//
//
void NavMapKDTree::NearestWaypoint(Node* rootNode, Vec3f pos, unsigned int depth) {
	if (rootNode == NULL) {
		return;
	}

	float newSquaredDistance = std::powf((rootNode->m_waypoint->Position().x - pos.x), 2) / 2 + std::powf((rootNode->m_waypoint->Position().y - pos.y), 2) / 2;
	newSquaredDistance = std::fabs(newSquaredDistance);

	float currSquaredDistance = std::powf((m_nearestWP->Position().x - pos.x), 2) / 2 + std::powf((m_nearestWP->Position().y - pos.y), 2) / 2;
	currSquaredDistance = std::fabs(currSquaredDistance);

	if (newSquaredDistance < currSquaredDistance) {
		m_nearestWP = rootNode->m_waypoint;
	}

	NearestWaypoint(rootNode->left, pos, depth + 1);
	NearestWaypoint(rootNode->right, pos, depth + 1);
}
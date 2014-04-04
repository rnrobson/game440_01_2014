// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "NavMapKDTree.h"

////
////
//// NavMapKDTree()
////
////
//NavMapKDTree::NavMapKDTree(int dimen) {
//
//}

//
//
// ~NavMapKDTree()
//
//
NavMapKDTree::~NavMapKDTree() {
	if (m_root) {
		delete m_root;
		m_root = nullptr;
	}
}

//
//
// NavMapKDTree::Insert()
//
//
void NavMapKDTree::Insert(Waypoint* wp) {
	Insert(m_root, new Node(wp));
}

//
//
// NavMapKDTree::Insert()
//
//
void NavMapKDTree::Insert(Node*& rootNode, Node* newNode) {
	// This or NearestWaypoint() isn't working properly
	// It's because of depth.. working on it
	if (rootNode == NULL) {
		rootNode = newNode;
	}
	else {
		Node* parent = m_root;
		Node* current = m_root;

		int currentDepth = 0;

		while (true) {
			parent = current;

			if (currentDepth % 2 == 0) {
				if (newNode->m_waypoint->Position().x < parent->m_waypoint->Position().x) {
					printf("Depth x: %i\n", currentDepth);
					current = current->left;

					if (!current) {
						parent->left = newNode;
						return;
					}
				}
				else {
					current = current->right;

					if (!current) {
						parent->right = newNode;
						return;
					}
				}
			}
			else {
				printf("Depth y: %i", currentDepth);
				if (newNode->m_waypoint->Position().y < parent->m_waypoint->Position().y) {
					current = current->left;

					if (!current) {
						parent->left = newNode;
						return;
					}
				}
				else {
					current = current->right;

					if (!current) {
						parent->right = newNode;
						return;
					}
				}
			}

			if (++currentDepth >= m_dimensions) {
				currentDepth = 0;
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

	NearestWaypoint(m_root, pos);

	return m_nearestWP;
}

//
//
// NavMapKDTree::NearestWaypoint()
//
//
void NavMapKDTree::NearestWaypoint(Node* rootNode, Vec3f pos) {
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

	NearestWaypoint(rootNode->left, pos);
	NearestWaypoint(rootNode->right, pos);
}
// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include "Vec3f.h"
#include "Waypoint.h"

class NavMapKDTree {
private:
	class Node {
		Node* right;
		Node* left;

		Waypoint* m_waypoint;

		Node();
		Node(Waypoint* wp) : m_waypoint(wp) {}
		~Node() {
			if (right) {
				delete right;
				right = nullptr;
			}

			if (left) {
				delete left;
				left = nullptr;
			}
		}

		friend class NavMapKDTree;
	};

	Node* m_root;
	Waypoint* m_nearestWP;

	int m_dimensions;

	void Insert(Node*& rootNode, Node* newNode);
	void TestTraverseInOrder(Node* rootNode);

	void NearestWaypoint(Node* rootNode, Vec3f pos);

public:
	NavMapKDTree() {};
	NavMapKDTree(int dimensions) : m_root(NULL), m_dimensions(dimensions) {};
	~NavMapKDTree();

	void Insert(Waypoint* wp);
	void TestTraverse();

	Waypoint* NearestWaypoint(Vec3f pos);
};
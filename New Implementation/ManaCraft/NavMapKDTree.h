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

		unsigned int m_depth;

		Waypoint* m_waypoint;

		Node();
		Node(Waypoint* wp) : m_waypoint(wp), m_depth(0) {}
		Node(Waypoint* wp, unsigned int depth) : m_waypoint(wp), m_depth(depth) {}

		friend class NavMapKDTree;
	};

	Node* m_root;
	Waypoint* m_nearestWP;

	void Insert(Node*& rootNode, Node* newNode, unsigned int depth);
	void TestTraverseInOrder(Node* rootNode);

	void NearestWaypoint(Node* rootNode, Vec3f pos, unsigned int depth);

public:
	NavMapKDTree() : m_root(NULL) {};

	void Insert(Waypoint* wp);
	void TestTraverse();

	Waypoint* NearestWaypoint(Vec3f pos);
};
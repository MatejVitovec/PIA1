#ifndef MESH_H
#define MESH_H
#include "PolygonBoundary.h"

class Mesh
{

    public:
        enum nodeOrientationType{top, right, bottom, left, topRight, bottomRight, bottomLeft, topLeft};

        struct BoundaryNode
        {
            nodeOrientationType orientation;
            unsigned char boundaryConditionType;
            double param1;
            double param2;
        };

        Mesh();
        Mesh(PolygonBoundary boundary, double dxx);
        virtual ~Mesh();

        std::vector<std::vector<short>> nodeList;
        std::vector<BoundaryNode> boundaryNodeList;

        void create(PolygonBoundary boundary);
        void merge(Mesh mesh2);

    private:
        double dx;
        double dy;
        int nodeSumX;
        int nodeSumY;

        bool isPointInside(PolygonBoundary boundary, Point point);
        bool isPointOnBoundary(PolygonBoundary boundary, Point point, PolygonBoundary::BoundarySegment& boundarySegment);
        nodeOrientationType getBoundaryNodeOrientation(int pointIndexX, int pointIndexY);
        void setBoundaryNodesOrientation();
        void removeCornerNodes();
        
};

#endif // MESH_H
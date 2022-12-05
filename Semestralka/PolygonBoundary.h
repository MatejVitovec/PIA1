#ifndef POLYGONBOUNDARY_H
#define POLYGONBOUNDARY_H

struct Point
{
    double x;
    double y;
};

class PolygonBoundary
{
    
    public:
        struct BoundarySegment
        {
            Point endPoint;
            unsigned char boundaryType;
            double param1;
            double param2;
        };
    
        PolygonBoundary();
        PolygonBoundary(std::vector<std::vector<double>> data);
        virtual ~PolygonBoundary();

        void load(std::vector<std::vector<double>> data);

        std::vector<BoundarySegment> boundaryEndPoints;
};

#endif // POLYGONBOUNDARY_H
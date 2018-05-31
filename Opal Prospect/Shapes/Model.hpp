#pragma once

#include <vector>
#include <array>
#include <string>

#include "NormalTriangle.hpp"

/*
Class that stores any generic model with indicies
*/

class Model
{
public:
    Model();

    void addTriangle(const NormalTriangle& triangle);

    void fillTriangleVertex(size_t index, std::array<float, 16>& data) const;
    void fillTriangleUV(size_t index, std::array<float, 12>& data) const;
    void fillTriangleNormal(size_t index, std::array<float, 16>& data) const;

    //gets
    std::string getModelName() const;
    std::string getTextureName() const;
    const NormalTriangle& getTriangle(size_t index) const;

    size_t getTriangleCount() const;
    virtual size_t getPointSize() const;
    virtual size_t getTotalSize() const; //total size in bytes

    //sets
    void setModelName(std::string name);
    void setTextureName(std::string name);

protected:
    void putPointInArray(const Point3D& point, float* data, size_t start)  const;
    void putPointInArrayExtra(const Point3D& point, float extra, float* data, size_t start)  const;

private:
    std::vector<NormalTriangle> triangles;
    std::string model_name;
    std::string texture_name;
};

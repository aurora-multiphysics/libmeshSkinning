#include "genFullMesh.hpp"
#include "generateBoundaries.hpp"
#include "meshBoolean.hpp"

int main(int argc, char** argv)
{
    std::string appName(argv[0]);
    std::vector<char*> libmeshArgv = {(char*)appName.data()};
    std::string path, filepath, filenameNoExt, surfFilename, boundFilename, tetFilename; 
    std::string surfFilepath, boundFilepath, tetFilepath; 
    std::string filename(argv[1]);

    path = "./Meshes/";
    filepath = path + filename;
    filenameNoExt = filename.substr(0, filename.find("."));

    surfFilename = filenameNoExt + "_surf.e";
    boundFilename = filenameNoExt + "_bound_only.e";
    tetFilename = filenameNoExt + "_tet.e";

    surfFilepath = path + surfFilename; 
    boundFilepath = path + boundFilename;
    tetFilepath = path + tetFilename; 

    libMesh::LibMeshInit init(libmeshArgv.size() - 1, libmeshArgv.data());
    //Create mesh object to store original model mesh
    libMesh::Mesh mesh(init.comm());
    //Create mesh object to store surface mesh
    libMesh::Mesh surfaceMesh(init.comm());
    //Create mesh object to store vacuum mesh
    // libMesh::Mesh vacuumMesh(init.comm());
    libMesh::Mesh boundaryMesh(init.comm());

    // mesh.read(filepath);

    surfaceMesh.read(surfFilepath);

    boundaryMesh.read(boundFilepath);

    genBooleanBound(boundaryMesh, surfaceMesh, mesh);

    mesh.write("booleanTesting.e");
    // createEdgeMesh(surfaceMesh, boundaryMesh);

    // vacuumMesh.read(tetFilepath);

    // createFullGeometry(mesh, vacuumMesh);

    return 0;
}
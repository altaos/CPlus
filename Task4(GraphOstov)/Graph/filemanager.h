#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "graph.h"
#include <QFile>

class FileManager
{
private:
    static Node* getNode(std::string str);
    static int getNodeNumber(std::string str);
public:
    FileManager();

    static Graph* open(QString filename);
    static void save(Graph* graph,std::string filename);
};

#endif // FILEMANAGER_H

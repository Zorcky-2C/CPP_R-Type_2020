#include "sprite.hpp"

bool searchFolder(const char * baseDir)
{
    DIR *dir = opendir(baseDir);
    if(dir) 
    { 
        struct dirent *ent; 
        while((ent = readdir(dir)) != NULL) 
        { 
            if (strcmp(ent->d_name, "Ressources") == 0) {
                return true;
            }
        }
    } else {
        return false;
    }
    return false;
}

const char *findFolder()
{ 
    bool isIt = false;
    int i = 0;
    std::vector<const char *> path(12);
    path.at(0) = "./client";
    path.at(1) = "./client/Rtype";
    path.at(2) = "./client/Rtype/Ressources";
    path.at(3) = "./client/sprites";
    path.at(4) = "./client/src/Event";
    path.at(5) = "./client/src/Sprite";
    path.at(6) = "./client/src/Text";
    path.at(7) = "./client/src/Window";
    path.at(8) = "./CMakeFiles";
    path.at(9) = "./CMakeFiles/CompilerIdC";
    path.at(10) = "./CMakeFiles/CompilerIdCXX";
    path.at(11) = "./server";

    while (isIt != true && i != 11) {
        isIt = searchFolder(path.at(i));
        i++;
    }
    if (isIt == true) {
        i -= 1;
        return path.at(i);
    } else {
        return "./client";
    }
}
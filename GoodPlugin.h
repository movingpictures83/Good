#ifndef GOODPLUGIN_H
#define GOODPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class GoodPlugin : public Plugin
{
public: 
 std::string toString() {return "Good";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif

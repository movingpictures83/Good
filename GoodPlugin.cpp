#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "GoodPlugin.h"

void GoodPlugin::input(std::string file) {
 inputfile = file;
}

void GoodPlugin::run() {

}

void GoodPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime diversity alpha --i-table "+inputfile+" --p-metric goods_coverage --o-alpha-diversity "+file+"; unzip -jo "+file+" -d "+PluginManager::prefix()+"; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<GoodPlugin> GoodPluginProxy = PluginProxy<GoodPlugin>("Good", PluginManager::getInstance());

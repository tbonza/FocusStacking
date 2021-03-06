#include <iostream>
#include <boost/exception/all.hpp>
#include "ImageServer.h"

#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

using namespace LMFocusStack;
using namespace std;

int options(char ** argv) {
  
  const std::string help = "--help";
  if (argv[1] == help) {
    #include STR(L10N_LANG)
    std::wcout << rstr_help << std::endl;
    return -1;
  }
  else {
    return 0;
  }
}

int main(int argc, char ** argv) {
  
  if (argc >= 2 && options(argv) == -1){
    std::cout << "Program closing" << std::endl;

    return -1;
    
  }
  else {

    try
      {
	ImageServer server(argc, argv);

	server.start_server();
    
      }
    catch (std::exception& e)
      {
	std::cerr << "Exception: " << e.what() << "\n";
      }
    catch (boost::exception& e)
      {
	std::cerr << "Boost Exception: " << std::endl;
	std::cerr << diagnostic_information(e);
      }

    return 0;
  }
    
}

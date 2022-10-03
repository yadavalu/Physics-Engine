#pragma once

#include <iostream>

#ifndef DEBUG
#define DEBUG(s) std::cout << #s << ": " << s << std::endl;
#endif

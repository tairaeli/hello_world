#include "arg_manage.hpp"
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
  ArgManager args(argc, argv);

  std::vector<std::string> flags = args.GetFlagArgs();

  std::vector<std::string> non_flags = args.GetNonFlagArgs();

  if (std::find(flags.begin(), flags.end(), "-s") != flags.end())
  {
    std::sort(non_flags.begin(), non_flags.end(),
              [](std::string a, std::string b)
              { return a < b; });
  }

  if (std::find(flags.begin(), flags.end(), "-l") != flags.end())
  {
    std::transform(non_flags.begin(), non_flags.end(), non_flags.begin(),
              [](std::string a)
              { return a+" "+std::to_string(a.size());});
  }

  for (std::string arg : non_flags)
  {
    std::cout << arg << std::endl;
  }

  return 0;
}
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/regex.hpp>
#include <string>
#include <cuda_runtime.h>
#include "CudaHelpers.h"

int main()
{
  using namespace boost::lambda;
  typedef std::istream_iterator<int> in;
  boost::regex pat("^Subject: (Re: |Aw: )*(.*)");
  boost::smatch matches;
  std::string line("Subject: hello");
  if (boost::regex_match(line, matches, pat))
    std::cout << matches[2] << std::endl;
/*
  std::for_each(
      in(std::cin), in(), std::cout << (_1 * 3) << " ");
  std::cout << std::endl;
*/
  int deviceCount = 0;
  cudaError_t error_id = cudaGetDeviceCount(&deviceCount);

  if (error_id != cudaSuccess)
  {
    printf("cudaGetDeviceCount returned %d\n-> %s\n",
           static_cast<int>(error_id), cudaGetErrorString(error_id));
    printf("Result = FAIL\n");
    exit(EXIT_FAILURE);
  }
  if (deviceCount == 0)
  {
    printf("There are no available device(s) that support CUDA\n");
  }
  else
  {
    printf("Detected %d CUDA Capable device(s)\n", deviceCount);
  }
  int dev = 0, driverVersion = 0, runtimeVersion = 0;
  cudaSetDevice(dev);
  cudaDeviceProp deviceProp;
  cudaGetDeviceProperties(&deviceProp, dev);
  printf("\nDevice %d: \"%s\"\n", dev, deviceProp.name);
  cudaDriverGetVersion(&driverVersion);
  cudaRuntimeGetVersion(&runtimeVersion);
  printf("  CUDA Driver Version / Runtime Version          %d.%d / %d.%d\n",
          driverVersion / 1000, (driverVersion % 100) / 10,
          runtimeVersion / 1000, (runtimeVersion % 100) / 10);
  printf("  CUDA Capability Major/Minor version number:    %d.%d\n",
          deviceProp.major, deviceProp.minor);

  std::cout << "Global mem " << static_cast<float>(deviceProp.totalGlobalMem / 1048576.0f) << " MBytes" << std::endl;
  std::cout << "Multiprocessors " << deviceProp.multiProcessorCount << std::endl;
  std::cout << "clock rate in ghz " << deviceProp.clockRate * 1e-6f << std::endl;

  std::cout << "cudahelpers " << cudahelpers::deviceCount(5) << std::endl;
}

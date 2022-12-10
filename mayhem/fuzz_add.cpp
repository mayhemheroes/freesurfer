#include <fuzzer/FuzzedDataProvider.h>
#include <stdint.h>
#include <stdio.h>

#include <climits>

#include "fnvhash.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
  FuzzedDataProvider provider(data, size);
  FnvHash fh;
  std::vector< unsigned char > buf = provider.ConsumeBytes< unsigned char >(4000);
  fh.add(&buf[0], buf.size());

  return 0;
}
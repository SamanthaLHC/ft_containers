#!/bin/bash

echo "output diff:"
./ft_containers > test1
./std_containers > test2
diff test1 test2



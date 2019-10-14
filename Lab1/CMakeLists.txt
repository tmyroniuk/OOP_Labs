cmake_minimum_required(VERSION 3.14)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp BaseList/BaseList.inl BaseList/BaseList.h List/List.inl List/List.h Vector.cpp Vector.h Address/AddressHolder.cpp Address/AddressHolder.h Address/IPv4.cpp Address/IPv4.h Address/Address.cpp Address/Address.h Address/IPv6.cpp Address/IPv6.h Address/MAC.cpp Address/MAC.h Address/IPv4_CIDR.cpp Address/IPv4_CIDR.h Address/IPv6_CIDR.cpp Address/IPv6_CIDR.h)
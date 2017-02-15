#!/bin/bash
. ./tools/pre.sh
echo "target=$TARGET, prefix=$PREFIX";
mkdir tmp && cd tmp;
wget http://mirrors.concertpass.com/gcc/releases/gcc-4.9.4/gcc-4.9.4.tar.gz
wget https://ftp.gnu.org/gnu/binutils/binutils-2.27.tar.gz
echo "extracting binutils";
tar xf binutils-2.27.tar.gz
echo "extracting gcc";
tar xf gcc-4.9.4.tar.gz
echo "extraction done";
echo "-----------------------------------";
mkdir build-binutils && cd build-binutils;
../binutils-2.27/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make -j4
make install
cd ..
mkdir build-gcc && cd build-gcc;
../gcc-4.9.4/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc -j6
make all-target-libgcc -j6
sudo make install-gcc
sudo make install-target-libgcc
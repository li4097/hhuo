# hhuo
network for fun! hhuo is a sample network, and you can use for anything base tcp or http. Just have fun!

1. things to start this network.
	(1): install jsoncpp 
	git clone https://github.com/liumao/jsoncpp.git 
	cd jsoncpp
	cmake ./
	make & sudo make install 
	
	(2): install openssl 
	git clone https://github.com/liumao/openssl.git
	cd openssl
	sudo ./config
	sudo make & sudo make install

	(3): install zlib 
	git clone https://github.com/liumao/zlib.git
	cd zlib
	make & sudo make install

	(4): install redis
	git clone https://github.com/liumao/redis.git
	cd redis 
	make & sudo make install

	(5): install hiredis
	git clone https://github.com/liumao/hiredis.git
	cd hiredis
	make & sudo make install

	(6): install glog
	git clone https://github.com/liumao/glog.git
	cd glog
	cmake ./
	make & sudo make install

	(7): install mysql
	for ubuntu or debian
	sudo apt-get install mysql-server
	sudo apt-get install mysql-client
	sudo apt-get install libmysqlclient-dev

	for centos
	sudo yum install -y mysql-server mysql mysql-deve

2. now, let us have fun.
	sudo mkdir build
	cd build
	cmake ../
	make 
	./bin/test4server

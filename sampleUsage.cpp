
#include <iostream>
#include <string>
#include<vector>
#include "ConfigReader.h"
using namespace std;

int main(){

	ConfigReader conf;
	conf.parseFile("settings.conf");
	conf.setSection("ENCODER_RATIOS");
	cout << conf.getInt("motor1")  << endl;
	cout << conf.getInt("motor2") <<endl;
	cout << conf.getString("motor1") ;
	cout << "\n";
	conf.setSection("CONNECTION");
	cout << conf.getString("ipaddress");
	




	return 1;
}
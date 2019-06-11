#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
	ifstream in("dat.txt");
	ofstream o_ax("ax.dat"), o_ay("ay.dat"),o_az("az.dat"), o_lati("latitude.dat"), o_lon("longtitude.dat"), \
			 o_h("height.dat"), o_head("heading.dat"), o_v("velocity.dat"), o_p("pithch.dat"), o_r("roll.dat"), o_y("yaw.dat");
			 

	string line, word;
	unsigned int  cnt = 0, pos;
	
	while(getline(in, line)){
		istringstream record(line);
		while(record >> word){
			if((pos = word.find_first_of(':')) == -1)
				continue;
			word = word.erase(0, pos+1);
			cout << stod(word) << endl;
			
			cnt++;
			switch(cnt){
				case 1:
					o_ax << word << " "; break;
				case 2:
					o_ay << word << " "; break;
				case 3:
					o_az << word << " "; break;
				case 4:
					o_lati << word << " "; break;
				case 5:
					o_lon << word << " "; break;
				case 6:
					o_h << word << " "; break;
				case 7:
					o_head << word << " "; break;
				case 8:
					o_v << word << " "; break;
				case 9:
					o_p << word << " "; break;
				case 10:
					o_r << word << " "; break;
				case 11:
					o_y << word << " "; cnt = 0; break;
								
			}
			
		}
}
	
	return 0;
} 

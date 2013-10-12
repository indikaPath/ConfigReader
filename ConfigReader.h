#pragma once
#include <string>
#include <map>
#include<vector>
#include <exception>

/*
 * Written by Indika U Pathirage 
 * 
 * This software is distributed under AGPL V3 licence.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
*/

using namespace std;

class ConfigReader
{
public:
	ConfigReader(void);
	~ConfigReader(void);
	/* Read a config file (in windows INI format) into the internal data structure*/
	bool parseFile(string fileName);
	/* section has to be set before reading any key value pairs*/
	bool setSection(string s);
	/* checks if a key is present in the currently selected section*/
	bool keyPresent(string key);
	/* */
	int getInt(string key);
	double getDouble(string key);
	string getString(string key);
	bool clear();
	

private:
	typedef map<string,string> keyValMap;
	typedef map<string,keyValMap*> sectionMap;
	bool dataValid;
	string fileName;
	sectionMap dataMap;
	keyValMap* selectedSection;

	
	bool readFile(string fileName);
	string toLowerCase(string s);
	vector<string> tokenize(const  string  & inString, const  string  & theDelimiter= " " );
	string removeLeadTrailWhtspc(string s);

	/*struct section{
		string name;
		map<string,string>* keyMap;
		section(string s, map<string,string>* k): name(s){
			keyMap = k;
		}
	};*/
};


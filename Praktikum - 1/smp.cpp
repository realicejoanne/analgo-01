#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
 
const char *men_data[][6] = {
    { "victor", "bertha", "amy", "diane", "erika", "clare" },
    { "wyatt",  "diane", "bertha", "amy", "clare", "erika" },
    { "xavier", "bertha", "erika", "clare", "diane", "amy" },
    { "yancey", "amy", "diane", "clare", "bertha", "erika" },
    { "zeus",   "bertha", "diane", "amy", "erika", "clare" }
};
 
const char *women_data[][6] = {
    { "amy",    "zeus", "victor", "wyatt", "yancey", "xavier" },
    { "bertha", "xavier", "wyatt", "yancey", "victor", "zeus" },
    { "clare",  "wyatt", "xavier", "yancey", "zeus", "victor" },
    { "diane",  "victor", "zeus", "yancey", "xavier", "wyatt" },
    { "erika",  "yancey", "wyatt", "zeus", "xavier", "victor" }
};
 
typedef vector<string> PrefList;
typedef map<string, PrefList> PrefMap;
typedef map<string, string> Couples;
 
//Apakah yang pertama duluan muncul daripada yang kedua di preference list?
bool prefers(const PrefList &prefer, const string &first, const string &second){
    for (PrefList::const_iterator it = prefer.begin(); it != prefer.end(); ++it){
        if (*it == first) return true;
        if (*it == second) return false;
    }
    return false; //no preference
}
 
void check_stability(const Couples &engaged, const PrefMap &men_pref, const PrefMap &women_pref){
    cout << "Stablility:\n";
    bool stable = true;
    for (Couples::const_iterator it = engaged.begin(); it != engaged.end(); ++it){
        const string &bride = it->first;
        const string &groom = it->second;
        const PrefList &preflist = men_pref.at(groom);
		
        for (PrefList::const_iterator it = preflist.begin(); it != preflist.end(); ++it){
            //Pria pilih wanita
			if (*it == bride)
                break;
			
			//Pria pilih wanita lain dan wanita lain itu pilih pria tersebut
            if (prefers(preflist, *it, bride) && prefers(women_pref.at(*it), groom, engaged.at(*it))){
                cout << "\t" << *it <<
                    " prefers " << groom <<
                    " over " << engaged.at(*it) <<
                    " and " << groom <<
                    " prefers " << *it <<
                    " over " << bride << "\n";
                stable = false;
            }
        }
    }
    if (stable) cout << "\t(all marriages stable)\n";
}
 
int main(){
    PrefMap men_pref, women_pref;
    queue<string> bachelors;
 
    //Inisialisasi orang
    for (int i = 0; i < 5; ++i){
		//Inisialisasi preference
        for (int j = 1; j < 6; ++j){
			men_pref[men_data[i][0]].push_back(men_data[i][j]);
            women_pref[women_data[i][0]].push_back(women_data[i][j]);
        }
        bachelors.push(men_data[i][0]);
    }
	
	//(wanita) dengan (pria)
    Couples engaged;
 
    cout << "Matchmaking:\n";
    while (!bachelors.empty()){
        const string &suitor = bachelors.front();
        const PrefList &preflist = men_pref[suitor];
		
        for (PrefList::const_iterator it = preflist.begin(); it != preflist.end(); ++it){
            const string &bride = *it;
			
			//Wanita single
            if (engaged.find(bride) == engaged.end()){
                cout << "\t" << bride << " and " << suitor << "\n";
				//Dipasangkan
                engaged[bride] = suitor;
                break;
            }
			
            const string &groom = engaged[bride];
			
            if (prefers(women_pref[bride], suitor, groom)){
                cout << "\t" << bride << " dumped " << groom << " for " << suitor << "\n";
                bachelors.push(groom); //lepas mantan
                engaged[bride] = suitor; //pilih pasangan baru
                break;
            }
        }
        bachelors.pop();
    }
 
    cout << "Engagements:\n";
    for (Couples::const_iterator it = engaged.begin(); it != engaged.end(); ++it){
        cout << "\t" << it->first << " and " << it->second << "\n";
    }
 
    check_stability(engaged, men_pref, women_pref);
}

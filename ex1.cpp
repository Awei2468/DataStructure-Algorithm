#include<bits/stdc++.h>
#include<iostream>

using namespace std;

vector<string> func(string prefered, vector<string> &supports) {
    unordered_set<string> hash(supports.begin(), supports.end());
    unordered_map<string,vector<string>> ump; //(region,firmware support string vector)
    vector<string> res;
    string s;

    for (string &s : supports) {
        string region;
        for (int i = 0; i < s.size() && s[i] != '-'; ++i) {
            region += s[i];
        }
        //cout << region << endl;
        ump[region].push_back(s);
    }

    for (int i = 0; i < prefered.size(); ++i) {
        if (prefered[i] != ',') s += prefered[i];
        else {
            if (s.find("-") != s.npos) {
                if (hash.find(s) != hash.end()) {
                    res.push_back(s);
                }
            }
            else {
                for (string &rs:ump[s]) {
                    res.push_back(rs);
                }
            }
            s = "";
            ++i;
        }  
    }
    if (s.find("-") != s.npos) {
        if (hash.find(s) != hash.end()) {
            res.push_back(s);
        }
    }
    else {
        for (string &rs:ump[s]) {
            res.push_back(rs);
        }
    }

    return res;
    //time:O(n)
    //space:O(n)
}

int main() {
    
    vector<string> supports{"en-US", "fr-CA", "fr-FR"};
    vector<string> res = func("fr-FR, fr", supports);

    unordered_set<string> unique_res(res.begin(), res.end());

    for (auto &r : unique_res) {
        cout << r << " ";
    }

    return 0;
}



// The firmware we are writing contains user-facing strings that need to be localized based upon the language preferences of the calling application. Our firmware doesn't support every possible language that might be requested (yet!), but there is a set of languages that we do already support. We need to find the closest language that we can use based upon the application’s preferences.


// The calling application has defined its supported languages in the form of a comma-separated list of language tags. For example:
 
//   Acceptable Languages: en-US, fr-CA, fr-FR
 
// means that the application would accept:
 
//   1. English as spoken in the United States (most preferred)
//   2. French as spoken in Canada
//   3. French as spoken in France (least preferred)


// Write a function that receives two arguments:
// A string that contains a comma-separated list of the application’s preferred languages
// List of supported language tags that the Firmware currently supports


// and returns the list of language tags that will work for the calling application. The language tags should be returned in descending order of preference (the same order as they appeared in the application’s preferred languages).
 
// In addition to writing this function, you should use tests to demonstrate that it's correct, either via an existing testing system or one you create.
 
// Examples:
 
// parse_accept_language(
//   "en-US, fr-CA, fr-FR", # the application’s language preferences, a string
//   ["fr-FR", "en-US"]  	# the firmware’s supported languages, a set of strings
// )
// returns: ["en-US", "fr-FR"]
 
// parse_accept_language("fr-CA, fr-FR", ["en-US", "fr-FR"])
// returns: ["fr-FR"]
 
// parse_accept_language("en-US", ["en-US", "fr-CA"])
// returns: ["en-US"]






// Part 2
 
// Applications will often also include a language tag that is not region-specific - for example, a tag of "en" means "any variant of English". Extend your function to support these language tags by letting them match all specific variants of the language.
 
// Examples:
 
// parse_accept_language("en", ["en-US", "fr-CA", "fr-FR"])
// returns: ["en-US"]
 
// parse_accept_language("fr", ["en-US", "fr-CA", "fr-FR"])
// returns: ["fr-CA", "fr-FR"]
 
// parse_accept_language("fr-FR, fr", ["en-US", "fr-CA", "fr-FR"])
// returns: ["fr-FR", "fr-CA"]



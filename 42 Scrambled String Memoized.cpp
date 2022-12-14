// 42).  Scrambled String Memoized
// Video Link : https://youtu.be/VyHEglhbm-A  
// LeetCode problem link : https://leetcode.com/problems/scramble-string/submissions/ 

//                   ------->>>>>>>>>>>------------>>>>>>>>>>>>________CODE________<<<<<<<<<<<<------------<<<<<<<<<<<<<<<<<<<<<<<<<<<                   // 


class Solution {
public:
    
   unordered_map<string,int> m; 
    
    bool isScramble(string s1, string s2) {
       
   string key = s1 + " " + s2;
        
    // precheck the key ,whether it's available in map or not  
        
	if (m.find(key) != m.end())
		return m[key];

	if (s1.compare(s2) == 0) {
        
		return m[key] = true;
		
	}
        
	if (s1.length() <= 1) {
        
        // equal to is used also becasue if it was single character and was same with s2 then it
        //  would alrady has been returned true by above if statement 
        
		m[key] = false;
		return false;
	}
        
	int n = s1.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i), s2.substr(0, n - i))) ||
		        (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))) {
			flag = true;
			break;
		}
	}

      return m[key] = flag;  
        
        
    }
};



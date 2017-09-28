class Solution {
public:
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;

    string alnum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2code.find(longUrl) != url2code.end()) {
            return "http://tinyurl.com/"; + url2code[longUrl];
        }

        string code;
        while (true) {
            code = "";
            for (int i = 0; i < 6; i++) {
                int idx = random() % alnum.length();
                code += alnum[idx];
            }

            if (code2url.find(code) == code2url.end()) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
                break;
            }
        }

        return "http://tinyurl.com/"; + code;
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string s = "http://tinyurl.com/";;
        string code = shortUrl.substr(s.length());

        if (code2url.find(code) != code2url.end()) {
            return code2url[code];
        }

        return "";
    }
};


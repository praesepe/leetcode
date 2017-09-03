class WordDictionary {
private Map<Integer, List<String>> map;
    
    /** Initialize your data structure here. */
    public WordDictionary() {
        map = new HashMap<Integer, List<String>>();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        int index = word.length();
        List<String> list;
        
        if(!map.containsKey(index)){                
            list = new ArrayList<String>(); 
            list.add(word);
            map.put(index, list);    
        } else {
            map.get(index).add(word);
        }               
    }
    
    public boolean isMatched(String target, String str, int length) {
        for(int i = 0 ; i < length; i++){
            if(target.charAt(i) != str.charAt(i) && target.charAt(i) != '.')
                return false;
        }
        return true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        int index = word.length();
        if(!map.containsKey(index))     
            return false;
        
        List<String> list = map.get(index);
        for(String s: list) {   
            if(isMatched(word, s, index))
                return true;         
        }            
        
        return false;       
    }    
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */


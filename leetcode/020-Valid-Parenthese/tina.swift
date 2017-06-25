class Solution {

    
    func isValid(_ s: String) -> Bool {
        var stack: [Character] = []
        for character in s.characters {
            var assumExpected: Character?
            
            switch character {
            case "(", "{", "[":
                stack.append(character)
            case ")":
                assumExpected = "("
            case "}":
                assumExpected = "{"   
            case "]":
                assumExpected = "["
            default:
                return false
            }
            
            if let expected = assumExpected {
                if stack.isEmpty {
                    return false
                }
                if stack.last! != expected {
                    return false
                }
                
                stack.removeLast()
            }
        }
        
        return stack.isEmpty
    }
}

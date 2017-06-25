class Solution {
    func evalRPN(_ tokens: [String]) -> Int {
        var result = 0
        var stack : [Int] = []
        
        for token in tokens {
            if let num = Int(token) {
                stack.append(num)
                continue
            }
            
            let b = stack.popLast()!
            let a = stack.popLast()!

            switch token {
            case "+":
                result = a + b
            case "-":
                result = a - b
            case "/":
                result = a / b
            case "*":
                result = a * b
            default:
                print("Invalid token")
            }
            
            stack.append(result)
        }
        
        return stack.last!
    }
}

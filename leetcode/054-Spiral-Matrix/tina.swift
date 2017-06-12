class Solution {
    enum Direction : Int {
        case RIGHT = 0, DOWN, LEFT, UP
        static var count: Int { return Direction.UP.hashValue + 1}
    }

    let Step = [
        Direction.RIGHT.rawValue : [0, 1],
        Direction.DOWN.rawValue : [1, 0],
        Direction.LEFT.rawValue : [0, -1],
        Direction.UP.rawValue : [-1, 0]
    ]

    func goNext(pos: inout [Int], offset: [Int]) {
        pos[0] += offset[0]
        pos[1] += offset[1]
    }

    func turnDirection(direction : inout Int) {
        direction = (direction + 1) % Direction.count
    }

    func updateBoundary(boundary: inout [ClosedRange<Int>], direction: Int) {
        switch direction {
            case Direction.RIGHT.rawValue:
                boundary[1] = boundary[1].lowerBound + 1 ... boundary[1].upperBound
            case Direction.DOWN.rawValue:
                boundary[0] = boundary[0].lowerBound + 1 ... boundary[0].upperBound
            case Direction.LEFT.rawValue:
                boundary[1] = boundary[1].lowerBound ... boundary[1].upperBound - 1
            case Direction.UP.rawValue:
                boundary[0] = boundary[0].lowerBound ... boundary[0].upperBound - 1
            default:
                true
        }
    }

    func isBoundary(pos: [Int], direction: Int, boundary: [ClosedRange<Int>]) -> Bool {
        var result = false
        switch direction {
            case Direction.RIGHT.rawValue:
                result = boundary[1].contains(pos[1] + 1) != true
            case Direction.DOWN.rawValue:
                result = boundary[0].contains(pos[0] + 1) != true
            case Direction.LEFT.rawValue:
                result = boundary[1].contains(pos[1] - 1) != true
            case Direction.UP.rawValue:
                result = boundary[0].contains(pos[0] - 1) != true
            default:
                true
        }

        return result
    }

    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        if (matrix.count == 0) {
            return []
        }

        // initial
        let m = matrix.count
        let n = matrix[0].count

        var boundary: [ClosedRange<Int>] = [0...m - 1, 0...n - 1]
        var result: [Int] = []
        var pos: [Int] = [0, 0]
        var direction = Direction.RIGHT.rawValue

        // iterate
        while (true) {
            result.append(matrix[pos[0]][pos[1]])

            if (isBoundary(pos: pos, direction: direction, boundary: boundary)) {
                turnDirection(direction: &direction)
                
                // terminate: meet boundary again after turning direction
                if (isBoundary(pos: pos, direction: direction, boundary: boundary)) {
                    break
                }
                
                updateBoundary(boundary: &boundary, direction: direction)
            }

            goNext(pos: &pos, offset: Step[direction]!)
        }

        return result
    }
}

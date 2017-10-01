#import <Foundation/Foundation.h>

@interface Node : NSObject

@property (nonatomic, assign) NSInteger value;
@property (nonatomic, strong) Node *next;

- (instancetype)initWithValue:(NSInteger)value;
+ (Node *)middle:(Node *)root;
+ (Node *)reverse:(Node *)root;
+ (BOOL)isPalindrome:(Node *)root;

@end

@implementation Node

- (instancetype)initWithValue:(NSInteger)value
{
    self = [super init];
    if (self) {
        _value = value;
        _next = nil;
    }
    return self;
}

+ (Node *)middle:(Node *)root
{
    Node *node = root;
    Node *fastNode = root;
    
    while (fastNode || fastNode.next) {
        node = node.next;
        fastNode = (fastNode.next).next;
    }
    
    return node;
}

+ (Node *)reverse:(Node *)root
{
    Node *node = root;
    Node *prev = nil;
    Node *next = nil;
    
    while (node) {
        next = node.next;
        node.next = prev;
        prev = node;
        node = next;
    }
    
    return prev;
}

+ (BOOL)isPalindrome:(Node *)root
{
    if (!root || !root.next) return YES;
    
    Node *middle = [Node middle:root];
    Node *reversedMiddle = [Node reverse:middle];
    Node *node = reversedMiddle;
    
    while (node) {
        if (root.value != node.value) {
            [Node reverse:reversedMiddle];
            return NO;
        }
        
        root = root.next;
        node = node.next;
    }
    
    [Node reverse:reversedMiddle];
    return YES;
}

@end

int main(int argc, char * argv[]) {
    Node *node1 = [[Node alloc] initWithValue:3];
    Node *node2 = [[Node alloc] initWithValue:7];
    Node *node3 = [[Node alloc] initWithValue:7];
    Node *node4 = [[Node alloc] initWithValue:3];
    //Node *node5 = [[Node alloc] initWithValue:9];
    
    node1.next = node2;
    node2.next = node3;
    node3.next = node4;
    //node4.next = node5;
    
    NSLog(@"%d", [Node isPalindrome:node1]);
}

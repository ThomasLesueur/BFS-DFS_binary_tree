class Node:
    def __init__(self, value=None):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        if self.value != None:
            if value < self.value:
                if self.left is None:
                    self.left = Node(value)
                else:
                    self.left.insert(value)
            elif value > self.value:
                if self.right is None:
                    self.right = Node(value)
                else:
                    self.right.insert(value)
        else:
            self.value = value

    def breadth_first_search(self, root, target):
        to_visit = []
        if root:
            to_visit.append(root)
        current = root
        while len(to_visit) != 0:
            current = to_visit.pop(0)
            if current.value == target:
                return current
            if current.left != None:
                to_visit.append(current.left)
            if current.right != None:
                to_visit.append(current.right)
        return None

    def depth_first_search(self, root, target):
        
        if root.value > target:
            return self.depth_first_search(root.left, target)
        elif root.value < target:
            return self.depth_first_search(root.right, target)
        else:
            return root


def print_tree(root):
    if root != None:
        print_tree(root.left)
        print(root.value)
        print_tree(root.right)


if __name__ == '__main__':
    t = Node()
    t.insert(10)
    t.insert(4)
    t.insert(9)
    t.insert(3)
    t.insert(1)
    t.insert(2)
    t.insert(7)
    t.insert(5)
    t.insert(6)
    #print_tree(t)
    node = t.breadth_first_search(t, 0)
    if node == None:
        print("No result")
    else:
        print(node.value)
    node = t.breadth_first_search(t, 7)
    print(node.value)
    node = t.depth_first_search(t, 4)
    print(node.left.value)
import random
import string

NODE_COUNT_PER_LAYER = [4,3,2]

class Node:
    def __init__(self):
        self.children = []
        self.children_connection_weights = []
        self.node_name = ''.join([random.choice(string.ascii_letters) for i in range(3)])
    def make_children(self, current_layer_number, node_per_layer):
        #terminate the recursion
        if current_layer_number >= len(node_per_layer):
            return

        for i in range(node_per_layer[current_layer_number]):
            self.children.append(Node())
        
        self.children[0].make_children(current_layer_number + 1, node_per_layer)

        for i in range(1, len(self.children)):
            self.children[i].children = self.children[0].children[:]
    def adjust_child_weights(self, current_layer_number, node_per_layer):
        if current_layer_number >= len(node_per_layer):
            return
        self.children_connection_weights = [0.0] * len(self.children)
        for i in range(len(self.children)):
            self.children_connection_weights[i] = random.uniform(0, 1)
            self.children[i].adjust_child_weights(current_layer_number + 1, node_per_layer)
        return

    def indent_output(self, layer, node_per_layer):
        indent = '    ' * layer
        #terminate recursion
        if layer >= len(node_per_layer):
            print(f"{indent}{self.node_name} is connected to")
            return
        print(f"{indent}{self.node_name}")
        for i in range (len(self.children)):
            try:
                print(f"{indent}with weight {self.children_connection_weights[i]}")
            except:
                pass

            self.children[i].indent_output(layer + 1, node_per_layer)
        return

master = Node()

master.make_children(0,NODE_COUNT_PER_LAYER)

master.indent_output(0,NODE_COUNT_PER_LAYER)

print("After set weights")

master.adjust_child_weights(0,NODE_COUNT_PER_LAYER)

master.indent_output(0,NODE_COUNT_PER_LAYER)


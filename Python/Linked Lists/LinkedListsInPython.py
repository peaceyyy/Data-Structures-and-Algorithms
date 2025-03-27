class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = Node()

    def node_count(self)->int:
        count = 0
        trav = self.head

        while trav is not None:
            trav = trav.next
            count += 1
        
        return count


    def insertAtBeginning(self, data):
        newNode = Node(data)
        if self.head == None:
            self.head = newNode

        else:
            newNode.next = self.head
            self.head = newNode

    def insertAtKthPosition(self, data, k):
        newNode = Node(data)
        if k == 0:
            self.insertAtBeginning(self, newNode)

        else:
            j = 0
            trav = self.head

            while j < k:
                trav = trav.next
                j += 1

            if trav.next and trav.next.next:

                newNode.next = trav.next.next
                trav.next = newNode

            else:
                trav.next = newNode

    def insertAtEnd(self, data):
        newNode = Node(data)
        if self.head == None:
            self.insertAtBeginning(self, newNode)

        else:
            trav = self.head

            while trav.next != None:
                trav = trav.next

            trav.next = newNode
    


def main():

    linked_list = LinkedList()

    linked_list.insertAtBeginning(10)
    linked_list.insertAtBeginning(20)

    linked_list.insertAtEnd(30)
    linked_list.insertAtEnd(40)

    linked_list.insertAtKthPosition(25, 1)

    def print_list():
        current = linked_list.head
        while current is not None:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    print_list() 
    print(f"Node Count: {linked_list.node_count()}")


if __name__ == "__main__":
    main()

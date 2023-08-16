#Hash Table
class Node:
    def __init__(self, key=None, data=None):
        self.value = {}
        self.value[key] = data
        self.next = None

    def __repr__(self):
        return str(self.data)

class LinkedList:
    def __init__(self, head=None):
        self.head = head
        self.next = None
        self.count = 0

    def __str__(self):
        str_list = []
        current = self.head
        while current:
            str_list.append(str(current.value))
            current = current.next
        return "[" + "->".join(str_list) + "]"

    def __repr__(self):
        return str(self)

class HashTable:
    def __init__(self, size):
        self.size = size
        self.values = [None] * size
        self.length = 0
        
    def hash(self, key, size):
        hashCode = 0
        for i in range(len(key)):
            hashCode += ord(key[i])
        return hashCode % size

    def add(self, key, value):
        hashIndex = self.hash(key, self.size)
        node = Node(key, value)
        if not self.values[hashIndex]:
            self.values[hashIndex] = LinkedList(node)
        else:
            current = self.values[hashIndex].head
            while current.next:
                current = current.next
            current.next = node
        self.values[hashIndex].count +=1
        self.length +=1

    def search(self, key):
        hashIndex = self.hash(key, self.size)
        slot = self.values[hashIndex]
        current = slot.head
        if key in current.value:
            return current.value
        while current.next:
            if key in current.next.value:
                return current.next.value
            else:
                current = current.next
        return "Data not found"

    def remove(self, key):
        hashIndex = self.hash(key, self.size)
        slot = self.values[hashIndex]
        current = slot.head
        if key in current.value:
            current = current.next
            slot.count -=1
            self.length -=1
            return "Data was deleted successfully"
        while current.next:
            if key in current.next.value:
                current.next = current.next.next
                slot.count -=1
                self.length -=1
                return "Data was deleted successfully"
            else:
                current = current.next
        return "Data is not exhausting"

    def __repr__(self):
        return str(self.values)

ht = HashTable(5)
ht.add("John", "111-111-111")
ht.add("Taylor", "222-222")
ht.add("Krish", "333-333")
ht.add("Mack", "444-444")
ht.add("Den", "555-555")
ht.add("Mike", "666-666")
ht.add("Jack", "88-88-88")
ht.add("Jimmy", "99-99")
ht.add("Harry", "121-121")
ht.add("Meet", "232-232")
ht.add("Miraj", "454-454")
ht.add("Milan", "567-567")
print(ht)
#[
# [{'Taylor': '222-222'}->{'Mack': '444-444'}->{'Mike': '666-666'}->{'Meet': '232-232'}], 
# None, 
# [{'Jack': '88-88-88'}->{'Milan': '567-567'}], 
# [{'Krish': '333-333'}->{'Jimmy': '99-99'}->{'Harry': '121-121'}], 
# [{'John': '111-111-111'}->{'Den': '555-555'}->{'Miraj': '454-454'}]
# ]
print(ht.search('Den'))#{'Den': '555-555'}
print(ht.search('Jimmy'))#{'Jimmy': '99-99'}
print(ht.remove('Den'))#Data was deleted successfully
print(ht.search('Den'))#Data not found

print(ht)
#[
# [{'Taylor': '222-222'}->{'Mack': '444-444'}->{'Mike': '666-666'}->{'Meet': '232-232'}], 
# None, 
# [{'Jack': '88-88-88'}->{'Milan': '567-567'}], 
# [{'Krish': '333-333'}->{'Jimmy': '99-99'}->{'Harry': '121-121'}], 
# [{'John': '111-111-111'}->{'Miraj': '454-454'}]
# ]

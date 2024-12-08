class Node{
  constructor(val){
    this.val = val
    this.next = null
  }
}

class SinglyLinkedList2{
  constructor(){
    this.head = null
    this.length = 0
  }
  
  decLen() {this.length -= 1}
  incLen() {this.length += 1}
  zeroLen() {this.length = 0}
  getLength() {return this.length}
  isEmpty() {return this.length === 0}
  
  printList(curr = this.head)
  {
      let str = "";
      while (curr) {
          str += curr.val + "->";
          curr = curr.next;
      }
      console.log(str);
  }
  
  // push node to the last
  push(val){
    let newNode = new Node(val)
    if(this.head == null) {
      this.head = newNode
    }
    else {
      let curr = this.head
      while(curr.next) curr = curr.next
      curr.next = newNode
    }
    this.incLen()
    return this
  }
  
  search(val){
    let curr = this.head
    while(curr) {
      if(curr.val == val) return curr
      curr = curr.next
    }
    return null
  }
  
  getPos(val){
    let pos = 0, curr = this.head
    while(curr){
      if(curr.val === val) return pos
      curr = curr.next
      pos++
    }
    return -1
  }
  
  remove(val){
    // let targetNode = this.search(val)
    // if(!targetNode) return false
    
    // if(this.head.val == val) this.head = this.head.next
    // else {
    //   let curr = this.head
    //   while(curr){
    //     if(curr.next && curr.next.val == val) {
    //       curr.next = curr.next.next
    //       break
    //     }
    //     else curr = curr.next
    //   }
      
    // }
    // this.decLen()
    // return true
    
    let pos = this.getPos(val)
    if(pos == -1) return false
    else {
      return this.removeAt(pos)
    }
  }
  
  removeAt(pos){
    if(pos < 0 || pos >= this.length){
      return false
    } else if (pos == 0){
      return !!this.shift()
    } else if (pos == this.length - 1){
      return !!this.pop()
    } else {
      
      let prev = this.get(pos-1)
      let nodeToBeRemoved = prev.next
      prev.next = nodeToBeRemoved.next
      
      this.decLen()
      return true
    }
  }
  
  pop(){
    if(this.length <= 0) return undefined
    
    if(this.head.next == null) {
      let curr = this.head
      this.head = null
      this.zeroLen()
      return curr
    } 
    
    let curr = this.head, prev = this.head
    
    // while(curr){
    //   if(curr.val == tail.val && curr.next == null){
    //     break
    //   } else curr = curr.next
    // }
    
    while(curr.next){
      prev = curr
      curr = curr.next
    }
    
    prev.next = null
    
    this.decLen()
    return curr
  }
  
  shift(){
    if(this.length <= 0) return undefined
    
    if(this.head.next == null) {
      let curr = this.head
      this.head = null
      this.zeroLen()
      return this
    } 
    
    let newHead = this.head.next
    let oldHead = this.head
    oldHead.next = null
    this.head = newHead
    
    this.decLen()
    return this
  }
  
  unshift(val){
   let newHead = new Node(val)
   if(!this.head) this.head = newHead
   else {
      newHead.next = this.head
      this.head = newHead
    }
    
    this.incLen()
    return this.head
  }
  
  get(pos){
    if(pos >= this.length || pos < 0) return undefined
    
    let curr = this.head
    
    while(pos--){
      curr = curr.next
    }
    
    return curr
  }
  
  set(pos, val){
    let foundNode = this.get(pos)
    
    if(foundNode) {
      foundNode.val = val
      return true
    }
    return false
  }
  
  insert(pos, val){
    if(pos > this.length) return false
    else if(pos == this.length) return !!this.push(val)
    else if(pos == 0) return !!this.unshift(val)
    else {
      let newNode = new Node(val)
      // let curr = this.head, prev = this.head
    
      // while(pos--){
      //   prev = curr
      //   curr = curr.next
      // }
      
      // prev.next = newNode
      // newNode.next = curr
      
      let prev = this.get(pos - 1), temp = prev.next
      prev.next = newNode
      newNode.next = temp
      
      this.incLen()
      return true
    }
  }
  
  reverse(){
    let prev = null, curr = this.head, next = null
    
    while(curr){
      next = curr.next
      curr.next = prev
      prev = curr
      curr = next
    }
    
    this.printList(prev)
    return prev
  }
}

let list2 = new SinglyLinkedList2()
// console.log(list2)


list2.push(1)
list2.push(2)
list2.push(3)
// console.log(list2)

// list2.unshift("Gautam")
// console.log(list2)


// list2.remove(4)
// console.log(list2)


// console.log(list2.pop())
// console.log(list2)
// console.log(list2.pop())
// console.log(list2)
// console.log(list2.pop())
// console.log(list2)
// console.log(list2.pop())
// console.log(list2)

// list2.unshift("Jain")
// console.log(list2)
// list2.unshift("Gautam")
// console.log(list2)

// console.log(list2.shift())
// console.log(list2)
// console.log(list2.shift())
// console.log(list2)
// console.log(list2.shift())
// console.log(list2)
// console.log(list2.shift())
// console.log(list2)

// console.log(list2.get(1))
// console.log(list2.set(1, 'Gautam'))

// console.log(list2)
list2.insert(3, 'Gautam'))

list2.printList()
list2.reverse()

// console.log(list2.remove(2))
// console.log(list2)
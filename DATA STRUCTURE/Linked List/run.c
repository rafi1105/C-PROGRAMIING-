 // print link list 
 temp=head;
 while ( temp -> next != NULL )
 {
   printf (" the element is : %d", temp -> data  );
   temp = temp -> next;
 }

// insert first 
 newnode -> next= head;
 newnode = head; 

 // last insert 
  temp = head;
  while ( temp -> next != NULL )
  {
    temp = temp -> next;
    
  }
  temp -> next = newnode;
  newnode -> next = NULL;
  

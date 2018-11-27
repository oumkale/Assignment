void polyAdd(npode *ptr1,node *ptr2,node *ptr)
{
   while(ptr1->next && ptr2->next)
     {
        if(ptr1->pow>ptr2->pow)
        {
         ptr->coe=ptr1->coe;
         ptr->pow=ptr1->pow;
         ptr1=ptr1->next;
        }
       else if(ptr2->pow>ptr1->pow)
        {
         ptr->coe=ptr2->coe;
         ptr->pow=ptr2->pow;
         ptr2=ptr2->next;
        }
        else
        {
          ptr->pow=ptr1->pow;
          ptr->coe=ptr1->coe+ptr2->coe;
          ptr2=ptr2->next;
          ptr1=ptr1->next;
        }
        ptr->next=(node*)malloc(sizeof(node));
          ptr=ptr->next;
        
     }
     if(ptr1->next)
         ptrr=ptr1;
              
     if(ptr->next)
         ptrr=ptr2;
     
     while()
     {
      ptr->coe=ptrr->coe;
      ptr->pow=ptrr->pow;
      ptrr=ptrr->next;
      ptr->next=(node*)malloc(sizeof(node));
      ptr=ptr->next;
     }
     ptr->next=NULL;



}
 

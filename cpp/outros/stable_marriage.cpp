Initialize all men and women to free
while there exist a free man m who still has a woman w to propose to 
{
    w = m_s highest ranked such woman to whom he has not yet proposed
    if w is free
       (m, w) become engaged
    else some pair (m_, w) already exists
       if w prefers m to m_
          (m, w) become engaged
           m_ becomes free
       else
          (m_, w) remain engaged    
}
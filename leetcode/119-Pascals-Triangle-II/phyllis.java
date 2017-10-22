/*
  
                 1
                1 1      
               1 2 1
              1 3 3 1     
*/


class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<Integer>();
        int sum = 0;
        int tmp = 1;
       
        list.add(1);
        if(rowIndex >= 1)
            list.add(1);
        
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++){                        
                sum = tmp + list.get(j).intValue();
                tmp = list.get(j).intValue();
                list.set(j, sum);

            }
            
            list.add(1);            
        }
        
        return list;
    }
}

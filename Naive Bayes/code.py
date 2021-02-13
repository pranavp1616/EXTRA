import pandas as pd 

#------------------------------------------------------------------------

def conditionalProb(data,AColumn,A,BColumn,B):
    # A is an item in AColumn
    # B is an item in BColumn
    # calculates P(A|B) = P(A intersection B)/P(B)
    intersection = float(len (data[ (data.ix[:,data.columns.get_loc(AColumn)] == A)  & ((data.ix[:,data.columns.get_loc(BColumn)]) == B)]));  
    tot = float(len(data[((data.ix[:,data.columns.get_loc(BColumn)]) == B)]));
    return intersection/tot;

#------------------------------------------------------------------------


def naiveBayes(data,newRow,attributes,rClass):

    probList = {};
    totClasses = data[rClass].unique();

    for classifier in totClasses:
        print "\n";
        probClassifier = float(len ( data[ (data.ix[:,data.columns.get_loc(rClass)]) == classifier ] ) );
        totalLength = float(len(data));

        # P ( YES )
        probClassifier = float (probClassifier) / totalLength;
        print "Classifier : ",classifier,"\nProbability = ",probClassifier," x ";
        totalProb = probClassifier;        

        # Calculate P(yes|x1) * P(yes|x2) * .... P(yes|xn) * P(YES)           
        for x in newRow:
            probClassifierGivenX = conditionalProb(data,x,newRow[x],rClass,classifier);    
            print probClassifierGivenX," x ";
            totalProb = totalProb * probClassifierGivenX;

        print " = ",totalProb; 
        probList[classifier]=totalProb;
    
    # Find max probability class from probList
    maxProb = 0.0;
    totSum = 0;
    ans = "";
    for i in probList:
        totSum = totSum + probList[i];
    for i in probList:
        probList[i] = probList[i]/totSum;        
    
    for i in probList:
        if(probList[i]>maxProb):
            ans = i;
            maxProb = probList[i];
    print "\n",probList;            
    print "\nAnswer is ",ans,"\n";
    return ans;
        
        
#----------------------------------------------------------------------
if __name__ == "__main__":

    # To try with new data set change - newRow and rClass variable values
    
    #For data.csv - Dataset 1  
    data = pd.read_csv('data.csv')
    attributes = list(data.columns.values)
    rClass = "Play";
    newRow = {"Outlook":"rainy","Temperature":"cool","Humidity":"high","Windy":"yes"};
    naiveBayes(data,newRow,attributes,rClass);


#include <iostream>

using namespace std;

int main(){
    
	string Culori ("ROGVAI");
	string CodAles;
	string CodIntrodus;
	string Buline[4];
	int codIntrodus[4];
	int codAles[4];
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int n;
	int pauza = 100;
	int nrMax = 10;
	int verificare = 0;
	int counter = 0;
		
    	cout<<"\n**Mastermind**\n\n";
    	
    	// Mod de joc
    	/*
    	cout<<"Cum doriti sa jucati?\nSingur: 1 ; In doua persoane: 2\n\n";
    	*/
    checkpoint3:
    	nrMax = 10;
	cout<<"Alege culorile:\nRosu[R]: 0; Orange[O]: 1; Galben[G]: 2; Verde[V]: 3; Albastru[A]: 4; Indigo[I] 5;\n(Nu puteti alege doua culori identice)"<<endl;
    checkpoint1:
    	for(i = 0 ; i < 4 ; i++){
        	cin>>codAles[i];
        	if (codAles[i] > 5 || codAles[i] < 0){
        		cout<<"Nu ati ales corect culoarea!\nReintroduceti codul:"<<endl;
        		goto checkpoint1;
        	}
        	CodAles[i] = Culori[codAles[i]];
    	}
    	
	//verificare culori diferite
	
	for(i = 0 ; i < 4 ; i++){
		for(j = i ; j < 4 ; j++){
			if(CodAles[i] == CodAles[j+1]){
				cout<<"Aveti cel putin doua culori identice!\nReintroduceti codul:"<<endl;
				goto checkpoint1;
			}
		}
	}
	
	//afisare cod ales;
	
	j = 0;
    	cout<<"Codul este: "<<endl;
    	while(j < 4){
        	cout<<CodAles[j]<<"\t";
        	j++;
    	}
    	cout << endl;
 	
    checkpointContinuare:
    
	//Continuare!
	
	cout<<"Continuati?\n(Da: apasati 1 ; Nu: apasati 2)\n";
	cin>>n;
	switch(n){
		case(1):
			break;
		case(2):
			exit(1);
		default:
			goto checkpointContinuare;
			
	}
	while(pauza){
		cout<<endl;
		pauza--;
	}
	pauza = 100;
	
	cout<<"Incercari:"<<endl;
	
    checkpoint2:
    
	cout<<"Alege culorile:\nRosu[R]: 0; Orange[O]: 1; Galben[G]: 2; Verde[V]: 3; Albastru[A]: 4; Indigo[I] 5;"<<endl;	
	
	while(nrMax){
		nrMax--;
		for(i = 0 ; i < 4 ; i++){
        		cin>>codIntrodus[i];
        		if (codIntrodus[i] > 5 || codIntrodus[i] < 0){
        			cout<<"Nu ati ales corect culoarea!\nReintroduceti codul:"<<endl;
        			goto checkpoint2;
        		}
        		CodIntrodus[i] = Culori[codIntrodus[i]];
    		}
    		
    		cout<<"Codul ales este: "<<endl;
    		
    		//i = 0;

    		for(i = 0 ; i < 4 ; i++){
        		cout<<CodIntrodus[i]<<"\t";
    		}
    		cout << endl;
 	
		//Golire string buline
		for(i = 0 ; i < 4 ; i++){
			Buline[i] = ' ';
		}
		
		//adaugare buline in string Buline

		//Buline albe
		counter = 0;
		for(i = 0 ; i < 4 ; i++){
			for(j = 0 ; j < 4 ; j++){
				if(CodAles[i] == CodIntrodus[j]){
					Buline[counter] = 'x';
					counter++;
					break;
				}
			}
		}
		//Buline rosii
		counter = 0;		
		for (i = 0 ; i < 4 ; i++){
			if(CodAles[i] == CodIntrodus[i]){
				Buline[counter] = '*';
				counter++;
			}		
		}
						
		//afisare string buline
		cout<<"\n";
		cout<<" Ordinea stelutelor si x-urilor nu are relevanta\n * - Pentru culoare si pozitie corecte\n x - Pentru culoare corecta\n";
		for(i = 0 ; i < 4 ; i++){
			cout<<Buline[i]<<"\t";
		}
		cout<<"\n";
		
		//Verificare cod corect
    		i = 4;
    		verificare = 0;
    		while(i){
    			if (CodIntrodus[i-1] == CodAles[i-1]){
    				verificare++;
    			}
    			i--;
    		}
    		
    		
    		if(verificare == 4){
    			cout<<"\nFelicitari! Ati ghicit codul!\nDoriti sa jucat din\n(Da: apasati 1 ; Nu: apasati 2)\n";
    			cin>>n;
			switch(n){
				case(1):
					cout<<"\n\n\n";
					goto checkpoint3;
					break;	
				case(2):
					exit(3);
				default:
					exit(3);
			}
    		}
    		else{
    			cout<<"\nCod gresit!\n\n\nReincercati:"<<endl;
    			goto checkpoint2;
    		}

		
	}
	
	//finalizare / reluare
	cout<<"\nNu ati reusit sa ghiciti codul!\nDoriti sa jucat din\n(Da: apasati 1 ; Nu: apasati 2)\n";
	cin>>n;
	switch(n){
		case(1):
			cout<<"\n\n\n";
			goto checkpoint3;
			break;	
		case(2):
			exit(2);
		default:
			exit(2);
	}
    	return 0;
}

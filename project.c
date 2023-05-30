#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>


struct etudiant {
    int appoge ;
    char cin[10];
    char nom[50];
    char prenom[50];
    
};




struct livre  {
    char titre[10];
     char nom_auteur[20];
     int livredispo ;
     
};
 
struct reservation{
	
	int  etud_appoge ;
	char titre_livre[60];
 	char Datedeprendre[20] ;
	char Datederemise[20] ;
		
	
};

void ajouter_etudiant(struct etudiant etudiant[], int* nb_etudiant) {
	
	
    struct etudiant nouveau_etudiant;
    int appoge ; 
    printf("\t\t Entrez les informations du nouveau etudiant :\n");
    printf("\t\t appoge : ");
    scanf("%d",&appoge) ;
    fflush(stdin);
    nouveau_etudiant.appoge = appoge ; 
    printf("\t\t CIN : ");
    gets(nouveau_etudiant.cin);
    printf("\t\t Nom : ");
    gets(nouveau_etudiant.nom);
    printf("\t\t Prenom : ");
    gets(nouveau_etudiant.prenom);
    etudiant[*nb_etudiant] = nouveau_etudiant;
    (*nb_etudiant)++;
    printf("\t\t Le nouveau etudiant a ete ajoute avec succes.\n");
}





void ajouter_livre (struct livre livre[], int *nbr_livre ) {
    struct livre nouveau_livre;
    fflush(stdin);
    printf("\n\n\n\n\t\t Entrez les informations de la nouveau livre :\n");
    printf("\t\t titre : ");
    gets(nouveau_livre.titre); 
    printf("\t\t auteur : ");
    gets(nouveau_livre.nom_auteur);
    printf("\t\t le nombre des livres  : ");
    int g ;
    scanf("%d",&g);
    nouveau_livre.livredispo = g ;
    fflush(stdin);
    livre[*nbr_livre] = nouveau_livre;
    (*nbr_livre)++;
    printf("\t\t Le nouveau_livre a ete ajoutee avec succes\n");

}



void afficher_etudiant(struct etudiant etudiant[], int* nb_etudiant) {
 	system("cls");
	if(*nb_etudiant==0){
		printf("\t\t il n existe aucun etudiant .");
	}
	else{
		int i;
		for(i = 0 ; i <*nb_etudiant ; i++){
	      	  	printf("\t\t appoge   :  %d    CIN  :  %s   nom  :   %s   prenom  :  %s \n",etudiant[i].appoge,etudiant[i].cin,etudiant[i].nom,etudiant[i].prenom);
		}
	}
	
	getch();
	
	
}



void afficher_livres(struct livre livres[], int* nb_livre) {
 	system("cls");
	if(*nb_livre==0){
		printf("\t\t il n existe aucune livre.");
	}
	else{
		int i;
		for(i = 0 ; i <*nb_livre ; i++){
	      	  	printf("\t\t  titre  :  %s      nom_auteur :   %s   nombre des livres disponibles   :  %d \n",livres[i].titre,livres[i].nom_auteur,livres[i].livredispo);
		}
	}
	
	getch();

}


void reservation(struct reservation reserv[], int *nb_reserv  ){
    struct reservation nouvelle_reservation;
    
    printf("\n\n\n\n\t\t Entrez les informations de la nouvelle reservation :\n");
    printf("\t\t appoge : ");
    scanf("%d", &nouvelle_reservation.etud_appoge);
    printf("\t\tdonner le titre du livre:");
    fflush(stdin);
    gets(nouvelle_reservation.titre_livre);
    fflush(stdin);
    printf("\t\t Date de prendre (format yyyy-mm-dd): ");
    gets(nouvelle_reservation.Datedeprendre);
    printf("\t\t Date de remise (format yyyy-mm-dd): ");
    gets(nouvelle_reservation.Datederemise);
    reserv[*nb_reserv] = nouvelle_reservation;
    (*nb_reserv)++;
    printf("\t\t La nouvelle reservation a ete ajoutee avec succes.\n");
	
}


void afficher_reservation(struct reservation reserv[], int* nb_reserv) {
 	system("cls");
	if(*nb_reserv==0){
		printf("\t\t il n existe aucune reservation.");
	}
	else{
	     int i;
	     for(i = 0 ; i <*nb_reserv ; i++){
	      printf("\t appoge  :  %d  titre de livre : %s  Date de prendre  :  %s      Date de remise :   %s\n",reserv[i].etud_appoge,reserv[i].titre_livre,reserv[i].Datedeprendre,reserv[i].Datederemise);
		printf("\n______________________________________________________________________________________________________________________\n_");
	}
	}
	
	getch();


}


void Historique(struct reservation reserv[], int* nb_reserv){
	system("cls");
	if(*nb_reserv==0){
		printf("\t\t il n existe aucune reservation.");
	}
	else{
		int app ; 
		printf("entrez l appoge : ");
		scanf("%d",&app);
		int i ; 
		for(i = 0 ; i <*nb_reserv ; i++){
	      		if(app == reserv[i].etud_appoge){
	   			printf("\t appoge  :  %d  titre de livre : %s  Date de prendre  :  %s      Date de remise :   %s \n",reserv[i].etud_appoge,reserv[i].titre_livre,reserv[i].Datedeprendre,reserv[i].Datederemise);
				printf("\n______________________________________________________________________________________________________________________\n_");   			
			}
		}	
	}
	getch();
}	
		
	
int breakfunction(){
	int choixbreak ; 
	fflush(stdin);
	printf("\n\t\t  entrez     1 _ menu principal ") ;
	scanf("%d",&choixbreak);
	
    if(choixbreak == 1){
	return  0 ; 
	}
	else{
		printf("\n\t\t  Merci de entrer votre choix correctement : ") ;
		breakfunction() ; 	
	}
	
}


int main(){
	
	int nbetudiants = 0 ; 
	int nblivre = 0;
	int nbreserv=0;
	struct etudiant etudiants[500] ; 	
	struct livre livres[2000] ;
	struct reservation reserv[1000]; 

	
	int choix  ; 
	while(1){
		
		system("cls") ; 
		printf("\n\n\n\n\t\t Bonjour dans notre Bibliotheque  choisissez votre souhait : \n\n\n\n") ;  
		printf("\t\t 1 _ Ajouter etudiant. \n") ; 
		printf("\t\t 2 _ Ajouter livre. \n") ;
		printf("\t\t 3 _ Afficher etudiant. \n") ;
		printf("\t\t 4 _ Afficher livre. \n") ;
		printf("\t\t 5 _ Ajouter reservation. \n") ;
		printf("\t\t 6 _ Afficher reservation. \n") ; 
		printf("\t\t 7 _ Afficher Historique d un etudiant . \n") ; 
		printf("\n\n\t\t Merci d entrer votre choix : ");
		
		scanf("%d",&choix) ; 

		switch(choix){

        case 1 :
        	
        	system("cls") ; 
        	printf("\n\n\n\n\t\t Le Nombre de place disponible est %d \n\n", 500 - nbetudiants);
        	
        	if( 500 - nbetudiants > 1 ){
        		ajouter_etudiant(etudiants ,&nbetudiants) ; 
				}
	else{
		printf("\t\t  Desole il n ya pas des place disponible !!\n\n") ; 
		}
            breakfunction();
            break;
      
       
  	case 2:
		system("cls") ; 
        		printf("\n\n\n\n\t\t Le Nombre de place disponible est %d \n\n",2000- nblivre);
        	
        		if(2000-nblivre > 1 )  {
        			ajouter_livre(livres ,&nblivre) ; 
				}
		else{
			printf("\t\t  Desole il n ya pas des place disponible !!\n\n") ; 
		}	
			breakfunction();
            break;
    	case 3 :
        		afficher_etudiant(etudiants ,&nbetudiants) ; 
			breakfunction();
            break;
             
    	case 4 :
        		afficher_livres(livres ,&nblivre) ; 
			breakfunction();
            break;
   	case 5 :
    		system("cls") ; 
        		printf("\n\n\n\n\t\t Le Nombre de place disponible est %d \n\n",1000- nbreserv);
        	
        		if(1000-nbreserv > 1 )  {
        		reservation( reserv, &nbreserv  ) ; 
		}
		else{
			printf("\t\t  Desole il n ya pas des place disponible !!\n\n") ; 
		}	
		breakfunction();
            break;
    	case 6 :
    	    	afficher_reservation(reserv,&nbreserv);
    	    	breakfunction();
    	break;
   	case 7 : 
   		Historique(reserv,&nbreserv);
    		breakfunction();
    	break;	
    	default:
            	printf("\n\n\t\t Votre choix est incorrect !! \n\n");
        	 
	break ; 
	}
}

	
}
 


 

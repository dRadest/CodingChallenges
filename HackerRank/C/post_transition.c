#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n", t.name);
    int office_count = t.offices_count;
    post_office* offices = t.offices;
    for(int i=0; i<office_count; i++){
        printf("\t%d\n:", i);
        post_office current_office = offices[i];
        int packages_count = current_office.packages_count;
        for(int j=0; j<packages_count; j++){
            package current_package = current_office.packages[j];
            printf("\t\t%s\n", current_package.id);
        }
    }
}

// empty package for comparison
static const package empty_package;

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    // get both offices
    post_office* source_office = source->offices + source_office_index;
    post_office* target_office = target->offices + target_office_index;
    // get min and max weight accepted by the target office
    int min_weight = target_office -> min_weight;
    int max_weight = target_office -> max_weight;

    // variable to update the source packages array with after we're done moving packages
    package* temp = NULL;
    // variable for keeping track of packages to keep in the source
    int packages_kept = 0;
    // variable to store the weight of the current package
    int current_package_weight;
    // traverse through the source packages
    package* source_packages = source_office -> packages;
    package* target_packages = target_office -> packages;
    int source_packages_count = source_office -> packages_count;
    int target_packages_count = target_office -> packages_count;
    for (int i = 0; i < source_packages_count; ++i)
    {
    	// get the current package weight
    	current_package_weight = source_office -> packages[i].weight;
    	// check if package weight withing boundaries
    	if (current_package_weight >= min_weight && current_package_weight <= max_weight)
    	{
    		// increment the packages_count of the target office by one (we're adding one package)
    		target_office -> packages_count++; 
    		// reallocate the memory for the array of packages for the target office
    		target_office -> packages = (package*) realloc(target_office -> packages, sizeof(package) * target_office -> packages_count);
    		// add the package from the source to the target office
    		target_office -> packages[target_office -> packages_count-1] = source_office -> packages[i];
    	} else {
    		// increment number of packages kept by one (we're keeping one package)
    		packages_kept++;
    		// reallocate the memory for the temp array
    		temp = (package*) realloc(temp, sizeof(package) * packages_kept);
    		// move the package from source to temp
    		temp[packages_kept-1] = source_office -> packages[i];
    	}
    }
    // assign the temp to source
    source_office -> packages = temp;
    // update the source office packages count
    source_office -> packages_count = packages_kept;
    
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {	
    int max = target->offices[target_office_index].max_weight;
    int min = target->offices[target_office_index].min_weight;
    package* temp = NULL;
    int notaccept = 0, weight;
    post_office* s = source->offices + source_office_index;
    post_office* d = target->offices + target_office_index;
                         
    for(int i=0; i < s->packages_count; i++)
    {
        weight = s->packages[i].weight;
        if(weight <= max && weight >= min)
        {
            d->packages_count++;
            d->packages = (package*)realloc(d->packages, sizeof(package) * d->packages_count);
            d->packages[d->packages_count-1] = s->packages[i];         
        }
        else
        {
            notaccept++;
            temp = (package*)realloc(temp, sizeof(package) * notaccept);
            temp[notaccept-1] = s->packages[i];
        }
    }
    s->packages = temp;
    s->packages_count = notaccept;
}

town town_with_most_packages(town* towns, int towns_count) {
    // variables for current and top town
    town current_town, top_town;
    // number of packages in the current and top town
    int current_package_count;
    int top_town_package_count = 0;
    // traverse through the towns array
    for(int i=0; i<towns_count; i++){
        current_town = towns[i];
        // initialize the package count for current town to zero
        current_package_count = 0;
        // traverse through all the offices in the current down
        int current_offices_count = towns[i].offices_count;
        post_office* current_offices = towns[i].offices;
        for(int j=0; j<current_offices_count; j++){
            /* add number of packages of the current office 
            to the sum of all the packages count for current town */
            current_package_count += current_offices[j].packages_count;
        }
        // check if the packages count of the current city is higher than the top so far
        if(current_package_count > top_town_package_count){
            // if so, we found our new top town
            top_town = current_town;
            top_town_package_count = current_package_count;
        }
    }
    return top_town;
}

town* find_town(town* towns, int towns_count, char* name) {
    // traverse through all the towns and compare names with the one given
    for(int i=0; i<towns_count; i++){
        int res = strcmp(towns[i].name, name);
        if(res == 0){
            return towns + i;
        }
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
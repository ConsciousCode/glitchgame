/*
 * Classes are not allowed, use struct always.
class Name {
	//...
};
 *
 */

struct NameOfStruct {
	/**
	 * No access qualifiers, all public
	**/
	
	/**
	 * Field declarations
	**/
	
	/**
	 * Constructor, destructor, operator overloads
	**/
	
	/**
	 * Methods
	**/
};

template<typename T, typename S>
struct Tpl {
	/**
	 * No metaprogramming, treat templates as smart-macros
	**/
};

rettype func_name(type args) {
	switch(args) {
		case 0:
			break;
		
		case 1:
			break;
		case 2:
			//Related to 1
			break;
		
		default:
			//rest
	}
	
	if(args.x) {
		for(int i = 0; i < args.x; ++i) {
			do {
			
			}while(0);
			
			while(i) {
				--i;
			}
		}
	}
	else {
		for(auto n : args.it) {
			
		}
	}
}

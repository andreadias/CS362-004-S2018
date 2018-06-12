
/*
Andrea Dias (diasan)
So Jang (jangso)
Casey Whitt (whittc)
*/


import junit.framework.TestCase;


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public class ResultPairCorrect {
	      public String item;
	      public boolean valid;

	      public ResultPairCorrect(String item, boolean valid) {
	         this.item = item;
	         this.valid = valid;  //Whether the individual part of url is valid.
	      }
	   }
   
 //schemes
   public String URL_with_valid_schemes [] = {"http://www.google.com", "https://www.google.com"};
   public String URL_with_invalid_schemes [] = {"httpb://www.google.com", "http:www.google.com", "http:/www.google.com"};

//authorities
   public String URL_with_valid_authorities [] = {"http://www.google.com", "http://192.0.255.125", "https://oregonstate.edu"};
   public String URL_with_invalid_authorities [] = {"http://...google.com", "http://192.0.257.125", "http:// "};

//port
   public String URL_with_valid_port [] = {"http://www.google.com:1400", "http://192.0.255.125", "https://www.oregonstate.edu:65534"};
   public String URL_with_invalid_port [] = {"http://www.google.com:1zef", "http://192.0.255.125:-20", "https://www.oregonstate.edu:66537"};

 //path
   public String URL_with_valid_path [] = {"http://www.google.com/test", "http://192.0.255.125", "https://www.oregonstate.edu/123/file"};
   public String URL_with_invalid_path [] = {"http://www.google.com//", "http://192.0.255.125/..", "https://www.oregonstate.edu:/..//123/"};

 //query 
   public String URL_with_valid_query [] = {"http://www.google.com?action=view", "http://192.0.255.125"};
   public String URL_with_invalid_query [] = {"http://www.google.com? action[]", "http://www.google.com\\"};
   
   
   public void testManualTest()
   {
	   ResultPairCorrect[] testCases = {new ResultPairCorrect("httpwww.google.com", false),
			   					new ResultPairCorrect("http:www.google.com", false ),
			   					new ResultPairCorrect("http:/www.google.com", false),
			   					new ResultPairCorrect("http://www.google.com", true),
			   					new ResultPairCorrect("http/www.google.com", false),
			   					new ResultPairCorrect("http//www.google.com", false),
			   					new ResultPairCorrect("://www.google.com", false),
			   					//new ResultPairCorrect("ftp://www.google.com", true),		//errors out function if tested
			   					//new ResultPairCorrect("abc://www.google.com", false),		//errors out function if tested
			   					new ResultPairCorrect("www.google.com", true),
			   					new ResultPairCorrect("www.google.com:80", true),
			   					new ResultPairCorrect("http://1234ABCD", false),
			   					new ResultPairCorrect("http://255.255.255.255", true),
			   					new ResultPairCorrect("http://0.0.0.0", true),
			   					new ResultPairCorrect("http://256.256.256.256", false),
			   					new ResultPairCorrect("http://1.2.3", false),
			   					new ResultPairCorrect("http://1.2.3.4.5.", false),
			   					new ResultPairCorrect("http://0.0.0.0.", false),
			   					new ResultPairCorrect("http://", false),
			   					new ResultPairCorrect("http://:80", false),
			   					new ResultPairCorrect("http://www.google.com:80", true),
			   					new ResultPairCorrect("http://www.google.com:abc", false),
			   					new ResultPairCorrect("http://www.google.com:-5", false),
			   					new ResultPairCorrect("http://www.google.com:80?action=view", true),
			   					new ResultPairCorrect("http://www.google.com?action=view", true),
			   					new ResultPairCorrect("http://www.google.com:80?none", false),
			   					new ResultPairCorrect("http://www.google.com:80", true),
			   					new ResultPairCorrect("http://www.google.com/", true),
			   					new ResultPairCorrect("http://www.google.com/..", false),
			   					new ResultPairCorrect("http://www.google.com/../", false),
			   					new ResultPairCorrect("http://www.google.com/example", true),
			   					new ResultPairCorrect("http://www.google.com/example/", true),
			   					new ResultPairCorrect("http://www.google.com/example/file", true),
			   					new ResultPairCorrect("http://www.google.com/@@@", false),
			   					new ResultPairCorrect("http://www.google.com/@@@/file", false),
			   					new ResultPairCorrect("http://www.google.com:80/example?action=view", false),
			   					new ResultPairCorrect("", false)
	   };
	   
	   UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertTrue(urlTest.isValid("http://www.google.com"));
	   assertTrue(urlTest.isValid("http://www.google.com/"));
	   
	   
   		for(int i = 0; i < testCases.length; i++) {
   			boolean result = urlTest.isValid(testCases[i].item);
   			if(result == testCases[i].valid) {
   				//System.out.print(i + " " + "PASSED: " + testCases[i].item + ' ' + testCases[i].valid + ' ' + result);
   				//System.out.println();
   			} 
   			else {
   				System.out.print(i + " " + "FAILED: " + testCases[i].item + " ----> " + result);
   				System.out.println();
   			}
   		}
   
   }
   
   
// public String URL_with_valid_path []

   public void testYourFirstPartition() {

	   UrlValidator urlval = new UrlValidator();
	   for(int i = 0; i < 2; i++ ) {

		  boolean result = urlval.isValid(URL_with_valid_schemes[i]);
		  if(result == false) {
			  System.out.println(URL_with_valid_schemes[i]);
		  }
		  assertTrue(result); 
	   }   

	   for(int i = 0; i < 3; i++ ) {

			  boolean result = urlval.isValid(URL_with_invalid_schemes[i]);
			  if(result == true) {
				  System.out.println(URL_with_invalid_schemes[i]);
			  }
			  assertFalse(result); 
		   }
   }

   
public void testYourSecondPartition() {

	   UrlValidator urlval = new UrlValidator();

	   for(int i = 0; i < 3; i++ ) {
		  boolean result = urlval.isValid(URL_with_valid_authorities[i]);
		  if(result == false) {
			  System.out.println(URL_with_valid_authorities[i]);
		  }
		  assertTrue(result); 
	   }

	   for(int i = 0; i < 3; i++ ) {
			  boolean result = urlval.isValid(URL_with_invalid_authorities[i]);
			  if(result == true) {
				  System.out.println(URL_with_invalid_authorities[i]);
			  }
			  assertFalse(result); 

	   }
   }

public void testYourThirdPartition() {   

	   UrlValidator urlval = new UrlValidator();
	   for(int i = 0; i < 3; i++ ) {
		  boolean result = urlval.isValid(URL_with_valid_port[i]);
		  if(result == false) {
			  System.out.println(URL_with_valid_port[i]);
		  }
		  assertTrue(result); 
	   }

	   for(int i = 0; i < 3; i++ ) {

			  boolean result = urlval.isValid(URL_with_invalid_port[i]);
			  if(result == true) {
				  System.out.println(URL_with_invalid_port[i]);
			  }
			  assertFalse(result); 

		   }
}


public void testYourFourthPartition() {

	  
	   UrlValidator urlval = new UrlValidator();

	   for(int i = 0; i < 3; i++ ) {
		  boolean result = urlval.isValid(URL_with_valid_path[i]);
		  if(result == false) {
			  System.out.println(URL_with_valid_path[i]);
		  }
		  assertTrue(result); 
	   }
	   
	   for(int i = 0; i < 3; i++ ) {
			  boolean result = urlval.isValid(URL_with_invalid_path[i]);
			  if(result == true) {
				  System.out.println(URL_with_invalid_path[i]);
			  }
			  assertFalse(result); 

	   }   

}

public void testYourFifthPartition() {
/*
	   try {
		   // isvalid
	   }catch(Exception e) {
		   System.out.println(e.getMessage());
	   }
*/
	   UrlValidator urlval = new UrlValidator();
	   for(int i = 0; i < 2; i++ ) {
		  boolean result = urlval.isValid(URL_with_valid_query[i]);
		  if(result == false) {
			  System.out.println(URL_with_valid_query[i]);
		  }
		  assertTrue(result); 
	   }

	   for(int i = 0; i < 2; i++ ) {
			  boolean result = urlval.isValid(URL_with_invalid_query[i]);
			  if(result == true) {
				  System.out.println(URL_with_invalid_query[i]);
			  }
			  assertFalse(result); 
	   }   
}
   
   public class ResultPairTest {
	      public String item;
	      public boolean valid;

	      public ResultPairTest(String item, boolean valid) {
	         this.item = item;
	         this.valid = valid;  //Whether the individual part of url is valid.
	      }
	   }
   
   
   public void testIsValid()
   {
   	   	  ResultPairTest[] testCasesS = {new ResultPairTest("http://", true),
					new ResultPairTest("https://", true),
					new ResultPairTest("ftp://", true),
   	   	  };
	   	   
	   	   ResultPairTest[] testCasesAuthority = {new ResultPairTest("www.google.com", true),
  					new ResultPairTest("go.com", true),
  					new ResultPairTest("google.com", true),
  					new ResultPairTest("googlecom", false),
  					new ResultPairTest("google..com", false),
  					new ResultPairTest("amazon.com", true),
  					new ResultPairTest("0.0.0.0", true),
  					new ResultPairTest("1.2.3", false),
  					new ResultPairTest("wwwgoogle.com", false),
  					new ResultPairTest("wwwgooglecom", false),
  					new ResultPairTest("ww.google.com", false),

	   	   };

	   	   ResultPairTest[] testCasesPort = {new ResultPairTest(":80", true),
  					new ResultPairTest(":65535", true),
  					new ResultPairTest("80", false),
  					new ResultPairTest(":80a", false),
  					new ResultPairTest("::80", false),
  					new ResultPairTest(":-5", false),
  					new ResultPairTest("", true)			
	   	   };
	   	   
	   	   ResultPairTest[] testCasesPath = {new ResultPairTest("/test1", true),
  					new ResultPairTest("/t123", true),
  					new ResultPairTest("/$t123", false),
  					new ResultPairTest("/$t123//^", false),
  					new ResultPairTest("/example", true),
  					new ResultPairTest("/@@@@", false),
  					new ResultPairTest("@@@", false),
  					new ResultPairTest("", true),	 					
	   	   };
	   	   
	   	   ResultPairTest[] testCasesQuery = {new ResultPairTest("?action=view", true),
  					new ResultPairTest("?action=edit&mode=up", true),
  					new ResultPairTest("?actionmode=up", false),
  					new ResultPairTest("", true),	  					
	   	   };
	   	   
	   	    	     	   
	   	   UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   	   		assertTrue(urlTest.isValid("http://www.google.com"));
	   	   		assertTrue(urlTest.isValid("http://www.google.com/"));
	    		
	   		for (int i = 0; i < testCasesAuthority.length; i++) {  				   			
	   			for (int j = 0; j < testCasesPort.length; j++) {
	   				for (int k = 0; k < testCasesPath.length; k++) {		
	   					for (int m = 0; m < testCasesQuery.length; m++) {  		   							   						
	   						
	   						String c = testCasesAuthority[i].item + testCasesPort[j].item + testCasesPath[k].item + testCasesQuery[m].item;
	   						
	   						if (testCasesAuthority[i].valid == false
	   								|| testCasesPort[j].valid == false 
	   								|| testCasesPath[k].valid == false 
	   								|| testCasesQuery[m].valid == false) {
	   							
	   							System.out.print("FAILED: " + c);		  		                    
	   							System.out.println();	
	   						}
	   							else {	
	   							//System.out.print("PASSED: " + c);		  		                    
	   							//System.out.println();		
	   							}
	   						
	   			   		}
	   		   		}
		   		}
	   		}
	   	
	   	  }
   	   	  
   
   public static void main(String[] argv) {

	  UrlValidatorTest fct = new UrlValidatorTest("url test");
      fct.testManualTest();
      
      UrlValidatorTest fct1 = new UrlValidatorTest("1st partition");
      fct1.testYourFirstPartition();
      
      UrlValidatorTest fct2 = new UrlValidatorTest("2nd partition");
      fct2.testYourSecondPartition();
      
      UrlValidatorTest fct3 = new UrlValidatorTest("3rd partition");
      fct3.testYourThirdPartition();
      
      UrlValidatorTest fct4 = new UrlValidatorTest("4th partition");
      fct4.testYourFourthPartition();
      
      UrlValidatorTest fct5 = new UrlValidatorTest("5th partition");
      fct5.testYourFifthPartition();
      
      UrlValidatorTest fctprog = new UrlValidatorTest("program test");
      fctprog.testIsValid();
      
      
   }

}

#include <stdio.h>
#include <stdbool.h>

int checkErrors(FILE* file) {

	    char currChar;
	        int currCharPos = 0, currLine = 0;
		    int dqErrLine = 0, sqErrLine = 0, sqErrChar = 0, dqErrChar = 0, parErrLine = 0, parErrChar = 0, bracesErrLine = 0, bracesErrChar = 0,
			        bracketsErrLine = 0, bracketsErrChar = 0, braces = 0, brackets = 0, par = 0, dquotes = 0, squotes = 0;
		        bool dqOpened = false, sqOpened = false, comments = false;

			    while((currChar = getc(file)) != EOF){

				            if(comments && currChar == '\n') {
						                currCharPos = 0;
								            currLine++;
									                comments = false;
											        }

					            if (currChar == '/') {
									            currChar = getc(file);
										                if (currChar != '/') {
															                comments = true;
																	            }
												        }

						            if(!comments) {

								                switch(currChar) {
											                case '\n':
														                    currCharPos = 0;
																                        currLine++;
																			                    break;
																					                    case '\"':
																					                        if(dquotes == 0) {
																									                        dqOpened = true;
																												                        dquotes++;
																															                        dqErrLine = currLine;
																																		                        dqErrChar = currCharPos;
																																					                        break;
																																								                    }
																								                    dquotes--;
																										                        dqOpened = false;
																													                    break;
																															                    case 39: //ASCII for single quote. Don't know how to insert special chars in C.
																															                        if(squotes == 0) {
																																			                        sqOpened = true;
																																						                        squotes++;
																																									                        sqErrLine = currLine;
																																												                        sqErrChar = currCharPos;
																																															                        break;
																																																		                    }
																																		                    squotes--;
																																				                        sqOpened = false;
																																							                    break;
																																									                    case '(':
																																									                        if(par == 0) {
																																													                        parErrLine = currLine;
																																																                        parErrChar = currChar;
																																																			                    }
																																												                    par++;
																																														                        break;
																																																	                case ')':
																																																	                    if(par == 0) {
																																																				                            printf("There is a closing parenthesis at line %d, character position %d", currLine, currCharPos);
																																																							                            printf(" but no opening parenthesis was found.\n");
																																																										                        }
																																																			                        par--;
																																																						                    break;
																																																								                    case '[':
																																																								                        if(braces == 0) {
																																																												                        bracesErrLine = currLine;
																																																															                        bracesErrChar = currChar;
																																																																		                    }
																																																											                    braces++;
																																																													                        break;
																																																																                case ']':
																																																																                    if(braces == 0) {
																																																																			                            printf("There is a closing brace at line %d, character position %d", currLine, currCharPos);
																																																																						                            printf(" but no opening brace was found.\n");
																																																																									                        }
																																																																		                        braces--;
																																																																					                    break;
																																																																							                    case '{':
																																																																							                        if(brackets == 0) {
																																																																											                        bracketsErrLine = currLine;
																																																																														                        bracketsErrLine = currChar;
																																																																																	                    }
																																																																										                    brackets++;
																																																																												                        break;
																																																																															                case '}':
																																																																															                    if(brackets == 0) {
																																																																																		                            printf("There is a closing bracket at line %d, character position %d", currLine, currCharPos);
																																																																																					                            printf(" but no opening bracket was found.\n");
																																																																																								                        }
																																																																																	                        brackets--;
																																																																																				                    break;
																																																																																						                    default:
																																																																																						                        break;
																																																																																									            }

										        }
							    currCharPos++;
							        }

			        if (par > 0) {
					        printf("Found opening parenthesis at line %d, character position %d ", parErrLine, parErrChar);
						        printf(" but no closing parenthesis was found.\n");
							    }

				    if (brackets > 0) {
					            printf("Found opening bracket at line %d, character position %d ", bracketsErrLine, bracketsErrChar);
						            printf(" but no closing bracket was found.\n");
							        }

				        if (braces > 0) {
						        printf("Found opening brace at line %d, character position %d ", bracesErrLine, bracesErrChar);
							        printf(" but no closing brace was found.\n");
								    }

					    if(dqOpened) {
						            printf("Found incomplete double quotes at line %d, character position %d\n", dqErrLine, dqErrChar);
							        }

					        if(sqOpened) {
							        printf("Found incomplete single quotes at line %d, character position %d\n", sqErrLine, sqErrChar);
								    }

						    return 0;
}

int main(int argc, char* argv[]) {

	    if(argc == 2) {

		            FILE* file = fopen(argv[1], "r");

			            if(file == NULL) {
					                printf("Something's wrong with the file you've provided.\n");
							            return 0;
								            }

				            checkErrors(file);
					        } else if(argc > 2) {
							        printf("Please only provide one file.\n");
								    }
	        
	        return 0;
}

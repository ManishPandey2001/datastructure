import React, { useEffect, useState } from "react";
import hljs from "highlight.js/lib/core";
import cLang from "highlight.js/lib/languages/c";
import "highlight.js/styles/vs2015.css"; 
import "./strings.css";
import { Container, Card, Button, Row, Col } from "react-bootstrap";

hljs.registerLanguage("c", cLang);

const Strings1 = () => {
    const [codes, setCodes] = useState([]);
    const codeTitles = [
        "1. ENTER THE STRING FROM USER AND CONVERT IN UPPERCASE",
        "2. ENTER THE STRING FROM USER AND CONVERT IN LOWERCASE",
        "3. ENTER THE STRING FROM USER AND CONVERT INTO SENTENCE CASE",
        "4. ENTER THE STRING FROM USER AND CONVERT INTO TITLE CASE",
        "5. ENTER THE STRING FROM USER AND CONVERT INTO TOGGLE CASE",
        "6. ENTER THE STRING FROM USER AND FINAL LENGTH OF THE STRING",
        "7. ENTER TWO STRINGS FROM USER AND COMPARE THOSE STRINGS THAT THEY ARE EQUAL OR NOT",
        "8. ENTER TWO STRINGS FROM USER AND CONCATENATE THOSE STRINGS IN ANOTHER STRING AND DISPLAY THE ANSWER",
        "9. ENTER THE STRING FROM USER AND COPY IT INTO ANOTHER STRING VARIABLE",
        "10. ENTER THE STRING FROM USER, ENTER THE INDEX NUMBER AND PRINT CHARACTER PRESENT ON THAT INDEX",
        "11. ENTER THE STRING FROM USER AND CHECK ITS PALINDROME OR NOT",
        "12. ENTER THE STRING FROM THE USER AND PRINT EACH CHARACTER IN NEW LINE",
        "13. ENTER THE STRING FROM THE USER AND COPY REVERSE OF THE STRING INTO ANOTHER STRING ",
        "14. ENTER THE STRING FROM THE USER AND PRINT THE DIFFERENCE OF ASCII VALUE OF EACH CHARACTER",
        "15. ENTER THE STRING FROM THE USER, ENTER A CHARACTER ALSO AND SEARCH THE CHARACTER IN THE STRING",
        "16. ENTER THE STRING FROM THE USER, ALSO ENTER A CHARACTER AND PRINT THE INDEX OF THE CHARACTER IF IT IS EXIST IN THE STRING ELSE PRINT -1.",
        "17. ENTER THE STRING FROM THE USER, AND COUNT THE NUMBER OF VOWELS.",
        "18. ENTER THE STRING FROM THE USER AND CONVERT INTO AN INTEGER VALUE",
        "19. ENTER THE STRING FROM THE USER AND CONVERT INTO A FLOAT VALUE",
        "20. ENTER THE STRING FROM THE USER AND COUNT THE NUMBER OF CHARACTERS, WORDS, SPACES AND LINES",
        "21. PRINT ALL THE PERMUTATION OF A STRING I.E. ABCDE.",
        "22. ENTER THE STRING FROM THE USER, SORT THE STRING IN ASCENDING ORDER AND PRINT IT.",
        "23. ENTER A SENTENCE FROM USER AND THEN ENTER THE WORD AND COUNT THE OCCURENCE OF THAT WORD IN THE SENTENCE.",
        "24. ENTER A SENTENCE FROM USER AND THEN ENTER THE WORD AND REPLACE THAT WORD BY ANOTHER WORD.",
        "25. ENTER THE STRING FROM THE USER AND TRIM/ ELIMINATE THE SPACES FROM BOTH ENDS (IF ANY).",
        "26. ENTER THE STRING FROM USER AND SPLITS THE FIRST WORD AND SECOND WORD AND RETURN THE START INDEX OF THE SECOND WORD.",
        "27. DISPLAY THE STRING ON THE OUTPUT SCREEN BUT ASK THE TEXT ALIGNMENT OPTION GIVEN BY THE USER",
        "28. CREATE A DICTIONARY HAVING 10 WORDS AND THEIR MEANING WITH FOLLOWING OPERATIONS.",
        "29. ENTER THE STRING FROM USER AND CONVERT CHARACTERS INTO THEIR ASCII VALUES IN THE INTEGER ARRAY.",
    ];

    useEffect(() => {
        const fetchCodes = async () => {
            const loadedCodes = await Promise.all(
                Array.from({ length: 20 }, async (_, i) => {
                    const response = await fetch(`/code/strings/${i + 1}.c`);
                    const text = await response.text();
                    return text;
                })
            );
            setCodes(loadedCodes);
        };

        fetchCodes();
    }, []);

    useEffect(() => {
        codes.forEach((code, i) => {
            const codeBlock = document.getElementById(`code-${i}`);
            if (codeBlock) {
                hljs.highlightElement(codeBlock);
            }
        });
    }, [codes]);

    const handleCopyCode = (code) => {
        navigator.clipboard.writeText(code);
        alert("Code copied to clipboard!");
    };

    const handleRunCode = () => {
        if (window.confirm("Do you want to open the Programiz online compiler to run this code?")) {
            window.open("https://www.programiz.com/c-programming/online-compiler/", "_blank");
        }
    };

    return (
        <Container className="my-5">
            <h2 className="text-center mb-4">Strings Operations</h2>
            <Row xs={1} md={2} lg={2} className="g-4">
                {codes.map((code, index) => (
                    <Col key={index}>
                        <Card className="code-card shadow-sm">
                            <Card.Body className="card-body">
                                <Card.Title>{codeTitles[index]}</Card.Title>
                                <pre>
                                    <code id={`code-${index}`} className="language-c">
                                        {code}
                                    </code>
                                </pre>
                                <div className="d-flex justify-content-between mt-3">
                                    <Button variant="primary" onClick={() => handleCopyCode(code)}>
                                        Copy Code
                                    </Button>
                                    <Button variant="outline-success" onClick={handleRunCode}>
                                        Run on Programiz
                                    </Button>
                                </div>
                            </Card.Body>
                        </Card>
                    </Col>
                ))}
            </Row>
        </Container>
    );
};

export default Strings1;

import React, { useEffect, useState } from "react";
import hljs from "highlight.js/lib/core";
import cLang from "highlight.js/lib/languages/c";
import "highlight.js/styles/vs2015.css"; // Adjust to other available styles if needed
import "./searchingAlgorithms.css";
import { Container, Card, Button, Row, Col } from "react-bootstrap";

hljs.registerLanguage("c", cLang);

const SearchingAlgorithms = () => {
    const [codes, setCodes] = useState([]);
    const codeTitles = [
        "1. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION.",
        "2. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION.",
        "3. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION.",
        "4. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION.",
        "5. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH ITERATION.",
        "6. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION.",
        "7. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION.",
        "8. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH ITERATION.",
        "9. CALCULATE THE BEST AND WORST COMPLEXITY OF THE LINEAR SEARCHING ALGORITHM WITH EXACT TIME TAKEN BY THE ALGORITHM ON INTEGER ARRAY.",
        "10. CALCULATE THE BEST AND WORST COMPLEXITY OF THE BINARY SEARCHING ALGORITHM WITH EXACT TIME TAKEN BY THE ALGORITHM ON INTEGER ARRAY."
    ];

    useEffect(() => {
        const fetchCodes = async () => {
            const loadedCodes = await Promise.all(
                Array.from({ length: 10 }, async (_, i) => {
                    const response = await fetch(`/code/searchingalgorithms/${i + 1}.c`);
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
            <h2 className="text-center mb-4">Searching Algorithms Operations</h2>
            <Row xs={1} md={2} lg={2} className="g-4">
                {codes.map((code, index) => (
                    <Col key={index}>
                        <Card className="code-card shadow-sm">
                            <Card.Body >
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

export default SearchingAlgorithms;

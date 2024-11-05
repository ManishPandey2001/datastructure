import React, { useEffect, useState } from "react";
import hljs from "highlight.js/lib/core";
import cLang from "highlight.js/lib/languages/c";
import "highlight.js/styles/vs2015.css"; // Adjust to other available styles if needed
import "./recursion.css";
import { Container, Card, Button, Row, Col } from "react-bootstrap";

hljs.registerLanguage("c", cLang);

const Recursion = () => {
    const [codes, setCodes] = useState([]);
    const codeTitles = [
       "1. CALCULATE FACTORIAL OF A NUMBER USING RECURSION",
       "2. CALCULATE FIBONACCI OF A NUMBER USING RECURSION",
       "3. CALCULATE THE SUM OF NATURAL NUMBERS TILL 10 USING RECURSION.",
       "4. CONVERT A NUMBER INTO BINARY USING RECURSION",
       "5. FIND THE LARGEST ELEMENT IN THE INTEGER ARRAY USING RECURSION",
       "6. FIND THE SMALLEST ELEMENT IN THE INTEGER ARRAY USING RECURSION.",
       "7. ENTER THE NUMBER FROM THE USER AND ADD ALL DIGITS OF THE NUMBER USING RECURSION.",
       "8. FIND THE ARITHMETIC MEAN OF AN INTEGER ARRAY USING RECURSION."
    ];

    useEffect(() => {
        const fetchCodes = async () => {
            const loadedCodes = await Promise.all(
                Array.from({ length: 8 }, async (_, i) => {
                    const response = await fetch(`/code/recursion/${i + 1}.c`);
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
            <h2 className="text-center mb-4">Recursion Operations</h2>
            <Row xs={1} md={2} lg={2} className="g-4">
                {codes.map((code, index) => (
                    <Col key={index}>
                        <Card className="code-card shadow-sm">
                            <Card.Body>
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

export default Recursion;

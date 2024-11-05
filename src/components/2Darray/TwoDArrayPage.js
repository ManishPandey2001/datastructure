import React, { useEffect, useState } from "react";
import hljs from "highlight.js/lib/core";
import cLang from "highlight.js/lib/languages/c";
import "highlight.js/styles/vs2015.css"; // Adjust to other available styles if needed
import "./TwoDArrayPage.css";
import { Container, Card, Button, Row, Col } from "react-bootstrap";

hljs.registerLanguage("c", cLang);

const TwoDArrayPage = () => {
    const [codes, setCodes] = useState([]);
    const codeTitles = [
        "Enter a matrix of 4 rows and 2 columns from the user, display it in matrix format.",
        "Add two matrices entered by the user and display the result.",
        "Subtract two matrices entered by the user and display the result.",
        "Multiply two matrices entered by the user and display the result.",
        "Copy a matrix entered by the user to another matrix of the same size.",
        "Multiply a matrix by a scalar value and display the result.",
        "Create a Tic Tac Toe game using 2D arrays."
    ];

    useEffect(() => {
        const fetchCodes = async () => {
            const loadedCodes = await Promise.all(
                Array.from({ length: 7 }, async (_, i) => {
                    const response = await fetch(`/code/2darray/${i + 1}.c`);
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
            <h2 className="text-center mb-4">2D Array Operations</h2>
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

export default TwoDArrayPage;

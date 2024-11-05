import React, { useEffect, useState } from "react";
import hljs from "highlight.js/lib/core";
import cLang from "highlight.js/lib/languages/c";
import "highlight.js/styles/vs2015.css"; // Adjust to other available styles if needed
import "./linkedList.css";
import { Container, Card, Button, Row, Col } from "react-bootstrap";

hljs.registerLanguage("c", cLang);

const LinkedList = () => {
    const [codes, setCodes] = useState([]);
    const codeTitles = [
        "1. Implement the operations of single linked list storing integer values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "2. Implement the operations of single linked list storing integer values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "3. Implement the operations of single linked list storing integer values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "4. Implement the operations of doubly circular linked list storing integer values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "5. Implement the operations of single linked list storing string values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "6. Implement the operations of single circular linked list storing string values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "7. Implement the operations of doubly linked list storing string values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "8. Implement the operations of doubly circular linked list storing string values (insert at begin,insert at pos,insert at end,delete at begin,delete at end, delete at pos, isempty, isfull, display, search)",
        "9. Enter the 2 polynomial equations dynamically, add them and display the answer.",
        "10. Enter the 2 polynomial equations dynamically, subtract them and display the answer.",
        "11. Enter the 2 polynomial equations dynamically, multiply them and display the answer."
    ];

    useEffect(() => {
        const fetchCodes = async () => {
            const loadedCodes = await Promise.all(
                Array.from({ length: 11 }, async (_, i) => {
                    const response = await fetch(`/code/linkedlist/${i + 1}.c`);
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
            <h2 className="text-center mb-4">Linked List Operations</h2>
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

export default LinkedList;

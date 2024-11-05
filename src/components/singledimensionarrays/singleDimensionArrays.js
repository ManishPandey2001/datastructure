import React, { useEffect, useState } from "react";
import hljs from "highlight.js/lib/core";
import cLang from "highlight.js/lib/languages/c";
import "highlight.js/styles/vs2015.css"; // Adjust to other available styles if needed
import "./singleDimensionArrays.css";
import { Container, Card, Button, Row, Col } from "react-bootstrap";

hljs.registerLanguage("c", cLang);

const SingleDimensionArrays = () => {
    const [codes, setCodes] = useState([]);
    const codeTitles = [
        "1. Enter an array from user and display all the value",
        "2. Enter an array from user and print the array in reverse order",
        "3. Enter an array from user and copy the array into second array",
        "4. Enter an array from user and copy it into another array in reverse order",
        "5. Enter an array from user and print the number which is even",
        "6. Enter an array from user and print the number which is positive",
        "7. Enter an array from user and square all the values of array",
        "8. Enter an array from user and find maximum and minimum value",
        "9. Enter an array from user and find the k-th smallest value",
        "10. Enter an array from user and add all values",
        "11. Enter an array from user and find the duplicate values",
        "12. Enter an array from user and remove the duplicate values and fill with zero",
        "13. Enter an array from user and count the duplicate values",
        "14. Enter an array from user and print all possible combinations of the elements",
        "15. Enter an array from user and print all the palindrome numbers",
        "16. Enter two arrays from the user and check they are same or not",
        "17. Merge the two sorted arrays into one array but in sorted order",
        "18. Find the local minima in the array",
        "19. Find the local maxima in the array",
        "20. Trapping Rain Water Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining."
    ];

    useEffect(() => {
        const fetchCodes = async () => {
            const loadedCodes = await Promise.all(
                Array.from({ length: 20 }, async (_, i) => {
                    const response = await fetch(`/code/singledimensionarrays/${i + 1}.c`);
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
            <h2 className="text-center mb-4">Single Dimension Array Operations</h2>
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

export default SingleDimensionArrays;

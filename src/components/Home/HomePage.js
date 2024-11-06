import React from "react";
import {
    Container,
    Button,
    Row,
    Col,
    Card,
} from "react-bootstrap";
import { Link } from "react-router-dom"; // Import Link from react-router-dom
import "./HomePage.css"; // Custom styles

const data = [
    {
        icon: 'bi-diagram-2',
        title: '2D Array',
        link: '/2darray' 
    },
    {
        icon: 'bi-graph-up',
        title: 'Graph',
        link: '/Graph'
    },
    {
        icon: 'bi-link-45deg',
        title: 'Linked List',
        link: '/Linkedlist'
    },
    {
        icon: 'bi-queue',
        title: 'Queues',
        link: '/Queque'
    },
    {
        icon: 'bi-arrow-repeat',
        title: 'Recursion',
        link: '/Recursion'
    },
    {
        icon: 'bi-search',
        title: 'Searching Algorithms',
        link: '/Searchingalgorithms'
    },
    {
        icon: 'bi-text-paragraph',
        title: 'Strings',
        link: '/String'
    },
    {
        icon: 'bi-stack',
        title: 'Stacks',
        link: '/Stack'
    },
    {
        icon: 'bi-tree',
        title: 'Trees',
        link: '/Tree'
    },
    {
        icon: 'bi-diagram-3',
        title: 'Single Dimension Array',
        link: '/SingleDimensionArray'
    },
    {
        icon: 'bi-sort-numeric-down',
        title: 'Sorting Algorithms',
        link: '/SortingAlgorithms'
    },
    {
        icon: 'bi-person-circle',
        title: 'About Us',
        link: '/AboutUs'
    }
];

const HomePage = () => {
    return (
        <>
            {/* Hero Section */}
            <Container fluid className="hero-section text-light text-center">
                <Container>
                    <Row className="align-items-center">
                        <Col md={6}>
                            <h1>
                                Power Up Your Programming: Learn Essential Data Structures
                            </h1>
                            <div className="d-flex justify-content-center">
                                <Button
                                    variant="light"
                                    className="me-2"
                                    href="https://www.w3schools.com/dsa/index.php"
                                >
                                    Get Started
                                </Button>
                                <Button variant="outline-light" href="https://www.youtube.com/watch?v=vwyld-xXl68">
                                    Watch Video
                                </Button>
                            </div>
                        </Col>
                        <Col md={6} className="d-none d-md-block">
                            <p>
                                A data structure is a specialized format for organizing and
                                storing data in a computer so that it can be accessed and used
                                efficiently. It's like a blueprint for how data is arranged and
                                manipulated within a program. Data structures provide a way to
                                handle information effectively, making it easier to process,
                                retrieve, and store data for various applications.
                            </p>
                        </Col>
                    </Row>
                </Container>
            </Container>

            {/* Feature Section */}
            <Container className="features py-5">
                <Row xs={1} md={3} className="g-4">
                    {data.map((section, index) => (
                        <Col key={index}>
                            <Card className="feature-card text-center">
                                <Card.Body>
                                    { <i className={`bi ${section.icon} feature-icon`}></i> }
                                    {section.link ? (
                                        <Link to={section.link}>
                                            <Card.Title >{section.title}</Card.Title>
                                        </Link>
                                    ) : (
                                        <Card.Title>{section.title}</Card.Title>
                                    )}
                                </Card.Body>
                            </Card>
                        </Col>
                    ))}
                </Row>
            </Container>
        </>
    );
};

export default HomePage;

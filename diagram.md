graph TD
    Browser["Browser\nBootstrap 5 UI"]

    subgraph Django["Django Application"]
        URLs["urls.py\nRoute dispatcher"]
        Views["views.py\nStep 1-4 + Results\nAJAX recalculate"]
        Forms["forms.py\nCriteriaForm\nCandidateValueForm"]
        Templates["templates/\nstep1-4, results\nbase.html"]
        Session["Django Session\nrole_title, criteria\ncandidates + values"]
        Scoring["scoring.py\nPure Python engine\nno ORM dependency"]
        Models["models.py\nHiringDecision\nHiringCriteria\nCandidate\nCandidateValue"]
        Admin["admin.py\nDjango Admin"]
    end

    DB[("SQLite Database")]

    Browser -->|HTTP Request| URLs
    URLs --> Views
    Views --> Forms
    Views --> Templates
    Views -->|read/write| Session
    Views -->|run_scoring| Scoring
    Views -->|save/load history| Models
    Models -->|ORM| DB
    Admin -->|manage| Models
    Templates -->|HTML response| Browser
